<?php
/**
 * @file
 * farmier_csa.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function farmier_csa_default_rules_configuration() {
  $items = array();
  $items['rules_farmier_csa_add_role'] = entity_import('rules_config', '{ "rules_farmier_csa_add_role" : {
      "LABEL" : "Farmier CSA Add Role",
      "PLUGIN" : "rule",
      "TAGS" : [ "farmier_csa" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "USES VARIABLES" : {
        "farmier_csa_user" : { "label" : "User", "type" : "user" },
        "farmier_csa_end_date" : { "label" : "CSA End Date", "type" : "date" }
      },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "farmier-csa-user" ],
            "roles" : { "value" : { "5" : "5" } }
          }
        },
        { "data_is" : {
            "data" : [ "farmier-csa-end-date" ],
            "op" : "\\u003E",
            "value" : [ "farmier-csa-user:field-csa-member-end-date" ]
          }
        }
      ],
      "DO" : [
        { "user_add_role" : {
            "account" : [ "farmier-csa-user" ],
            "roles" : { "value" : { "5" : "5" } }
          }
        },
        { "data_set" : {
            "data" : [ "farmier-csa-user:field-csa-member-end-date" ],
            "value" : [ "farmier-csa-end-date" ]
          }
        },
        { "schedule" : {
            "component" : "rules_farmier_csa_remove_role",
            "date" : [ "farmier-csa-end-date" ],
            "identifier" : "farmier_csa_end_membership_[farmier-csa-user:uid]",
            "param_farmier_csa_user" : [ "farmier-csa-user" ]
          }
        }
      ]
    }
  }');
  $items['rules_farmier_csa_line_item_membership'] = entity_import('rules_config', '{ "rules_farmier_csa_line_item_membership" : {
      "LABEL" : "Farmier CSA Line Item Membership",
      "PLUGIN" : "rule",
      "TAGS" : [ "farmier_csa" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "farmier_csa_user" : { "label" : "User", "type" : "user" },
        "farmier_csa_line_item" : { "label" : "Line item", "type" : "commerce_line_item" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "farmier-csa-line-item" ], "field" : "commerce_product" } },
        { "entity_has_field" : {
            "entity" : [ "farmier-csa-line-item:commerce-product" ],
            "field" : "field_farmier_csa_date_range"
          }
        }
      ],
      "DO" : [
        { "component_rules_farmier_csa_add_role" : {
            "farmier_csa_user" : [ "farmier_csa_user" ],
            "farmier_csa_end_date" : [
              "farmier-csa-line-item:commerce-product:field-farmier-csa-date-range:value2"
            ]
          }
        }
      ]
    }
  }');
  $items['rules_farmier_csa_payment'] = entity_import('rules_config', '{ "rules_farmier_csa_payment" : {
      "LABEL" : "Farmier CSA Payment",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "farmier_csa" ],
      "REQUIRES" : [ "commerce_order", "rules", "entity" ],
      "ON" : [ "commerce_payment_transaction_insert" ],
      "IF" : [
        { "commerce_order_contains_product_type" : {
            "commerce_order" : [ "commerce-payment-transaction:order" ],
            "product_type" : { "value" : { "farmier_csa_subscription" : "farmier_csa_subscription" } },
            "operator" : "\\u003E=",
            "value" : "1"
          }
        }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-payment-transaction:order:commerce-line-items" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "component_rules_farmier_csa_line_item_membership" : {
                  "farmier_csa_user" : [ "commerce-payment-transaction:order:owner" ],
                  "farmier_csa_line_item" : [ "list-item" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_farmier_csa_remove_role'] = entity_import('rules_config', '{ "rules_farmier_csa_remove_role" : {
      "LABEL" : "Farmier CSA Remove Role",
      "PLUGIN" : "rule",
      "TAGS" : [ "farmier_csa" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "farmier_csa_user" : { "label" : "User", "type" : "user" } },
      "IF" : [
        { "user_has_role" : {
            "account" : [ "farmier-csa-user" ],
            "roles" : { "value" : { "5" : "5" } }
          }
        }
      ],
      "DO" : [
        { "user_remove_role" : {
            "account" : [ "farmier-csa-user" ],
            "roles" : { "value" : { "5" : "5" } }
          }
        }
      ]
    }
  }');
  return $items;
}
