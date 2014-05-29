<?php
/**
 * @file
 * farm_csa.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function farm_csa_default_rules_configuration() {
  $items = array();
  $items['rules_farm_csa_subscribe_from_line_item'] = entity_import('rules_config', '{ "rules_farm_csa_subscribe_from_line_item" : {
      "LABEL" : "Farm CSA Subscribe from Line Item",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "line_item" : { "label" : "Line item", "type" : "commerce_line_item" } },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "line-item:order:uid" ] } },
        { "entity_has_field" : { "entity" : [ "line-item" ], "field" : "commerce_product" } },
        { "entity_is_of_bundle" : {
            "entity" : [ "line-item:commerce-product" ],
            "type" : "commerce_product",
            "bundle" : { "value" : { "farm_csa_subscription" : "farm_csa_subscription" } }
          }
        }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "log",
              "param_type" : "farm_csa_member_subscribe",
              "param_uid" : [ "site:current-user" ],
              "param_created" : "now",
              "param_changed" : "now"
            },
            "PROVIDE" : { "entity_created" : { "log_created" : "Created log" } }
          }
        },
        { "data_set" : {
            "data" : [ "log-created:field-farm-person" ],
            "value" : [ "line-item:order:owner" ]
          }
        },
        { "data_set" : {
            "data" : [ "log-created:field-farm-csa-products" ],
            "value" : [ "line-item:commerce-product" ]
          }
        },
        { "data_set" : {
            "data" : [ "log-created:field-farm-date-range" ],
            "value" : [ "line-item:commerce-product:field-farm-date-range" ]
          }
        },
        { "data_set" : {
            "data" : [ "log-created:field-farm-csa-order" ],
            "value" : [ "line-item:order" ]
          }
        },
        { "data_set" : { "data" : [ "log-created:name" ] } },
        { "entity_save" : { "data" : [ "log-created" ] } }
      ]
    }
  }');
  $items['rules_farm_csa_subscription_first_payment'] = entity_import('rules_config', '{ "rules_farm_csa_subscription_first_payment" : {
      "LABEL" : "Farm CSA Subscription First Payment",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "commerce_order", "commerce_payment", "rules", "entity" ],
      "ON" : { "commerce_payment_transaction_presave" : [] },
      "IF" : [
        { "commerce_order_contains_product_type" : {
            "commerce_order" : [ "commerce-payment-transaction:order" ],
            "product_type" : { "value" : { "farm_csa_subscription" : "farm_csa_subscription" } },
            "operator" : "\\u003E=",
            "value" : "1"
          }
        },
        { "commerce_payment_order_balance_comparison" : {
            "commerce_order" : [ "commerce-payment-transaction:order" ],
            "operator" : "=",
            "value" : [ "commerce-payment-transaction:order:commerce-order-total:amount" ]
          }
        },
        { "data_is" : {
            "data" : [ "commerce-payment-transaction:status" ],
            "value" : "success"
          }
        }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "commerce-payment-transaction:order:commerce-line-items" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "component_rules_farm_csa_subscribe_from_line_item" : { "line_item" : [ "list-item" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_farm_csa_warning_order_payment_before_owner'] = entity_import('rules_config', '{ "rules_farm_csa_warning_order_payment_before_owner" : {
      "LABEL" : "Farm CSA Warning: Order Payment Before Owner",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "warning" ],
      "REQUIRES" : [ "commerce_cart", "commerce_order", "rules", "entity" ],
      "ON" : { "commerce_payment_transaction_insert" : [] },
      "IF" : [
        { "NOT commerce_order_is_cart" : { "commerce_order" : [ "commerce-payment-transaction:order" ] } },
        { "commerce_order_contains_product_type" : {
            "commerce_order" : [ "commerce-payment-transaction:order" ],
            "product_type" : { "value" : { "farm_csa_subscription" : "farm_csa_subscription" } },
            "operator" : "\\u003E=",
            "value" : "1"
          }
        },
        { "data_is_empty" : { "data" : [ "commerce-payment-transaction:order:owner" ] } }
      ],
      "DO" : [
        { "drupal_message" : {
            "message" : "You\\u0027ve made a payment to a CSA order without a person assigned to it. The CSA subscription cannot be registered without a person assigned to it. To fix this, delete all payments from this order, and enter the person\\u0027s email address in the \\u0022Order contact e-mail\\u0022 field in the \\u003Ca href=\\u0022\\/admin\\/commerce\\/orders\\/[commerce-payment-transaction:order-id]\\/edit\\u0022\\u003Eorder edit form\\u003C\\/a\\u003E. Then reenter the payment. This will generate a new user account (if necessary) and a new subscription for that user.",
            "type" : "warning"
          }
        }
      ]
    }
  }');
  return $items;
}
