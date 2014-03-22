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
  $items['rules_farmier_csa_line_item_membership'] = entity_import('rules_config', '{ "rules_farmier_csa_line_item_membership" : {
      "LABEL" : "Farmier CSA Line Item Membership",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
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
        },
        { "OR" : [
            { "data_is" : {
                "data" : [
                  "farmier-csa-line-item:commerce-product:field-farmier-csa-date-range:value2"
                ],
                "op" : "\\u003E",
                "value" : [ "farmier-csa-user:field-csa-member-dates:value2" ]
              }
            },
            { "data_is_empty" : { "data" : [ "farmier-csa-user:field-csa-member-dates" ] } }
          ]
        }
      ],
      "DO" : [
        { "component_rules_farmier_csa_role_pre_member" : { "farmier_csa_user" : [ "farmier_csa_user" ] } },
        { "data_set" : {
            "data" : [ "farmier-csa-user:field-csa-member-dates" ],
            "value" : [ "farmier-csa-line-item:commerce-product:field-farmier-csa-date-range" ]
          }
        },
        { "component_rules_farmier_csa_reschedule_roles" : { "farmier_csa_user" : [ "farmier_csa_user" ] } }
      ]
    }
  }');
  $items['rules_farmier_csa_payment'] = entity_import('rules_config', '{ "rules_farmier_csa_payment" : {
      "LABEL" : "Farmier CSA Payment",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "farmier_csa" ],
      "REQUIRES" : [ "commerce_order", "rules", "entity" ],
      "ON" : { "commerce_payment_transaction_insert" : [] },
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
  $items['rules_farmier_csa_product_line_item_membership'] = entity_import('rules_config', '{ "rules_farmier_csa_product_line_item_membership" : {
      "LABEL" : "Farmier CSA Product Line Item Membership",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "farmier_csa" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "line_item" : { "label" : "Line item", "type" : "commerce_line_item" } },
      "IF" : [
        { "NOT data_is_empty" : { "data" : [ "line-item:order:uid" ] } },
        { "data_is" : {
            "data" : [ "line-item:order:state" ],
            "op" : "IN",
            "value" : { "value" : { "pending" : "pending", "completed" : "completed" } }
          }
        }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "user", "id" : [ "line-item:order:uid" ] },
            "PROVIDE" : { "entity_fetched" : { "order_owner" : "Order owner" } }
          }
        },
        { "component_rules_farmier_csa_line_item_membership" : {
            "farmier_csa_user" : [ "order-owner" ],
            "farmier_csa_line_item" : [ "line-item" ]
          }
        }
      ]
    }
  }');
  $items['rules_farmier_csa_reschedule_roles'] = entity_import('rules_config', '{ "rules_farmier_csa_reschedule_roles" : {
      "LABEL" : "Farmier CSA Reschedule Roles",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "TAGS" : [ "farmier_csa" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "USES VARIABLES" : { "farmier_csa_user" : { "label" : "Farmier CSA User", "type" : "user" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "NOT data_is_empty" : { "data" : [ "farmier-csa-user:field-csa-member-dates:value" ] } }
            ],
            "DO" : [
              { "schedule" : {
                  "component" : "rules_farmier_csa_role_member",
                  "date" : [ "farmier-csa-user:field-csa-member-dates:value" ],
                  "identifier" : "farmier_csa_begin_membership_[farmier-csa-user:uid]",
                  "param_farmier_csa_user" : [ "farmier-csa-user" ]
                }
              }
            ],
            "LABEL" : "farmier_csa_reschedule_role_member"
          }
        },
        { "RULE" : {
            "IF" : [
              { "NOT data_is_empty" : { "data" : [ "farmier-csa-user:field-csa-member-dates:value2" ] } }
            ],
            "DO" : [
              { "schedule" : {
                  "component" : "rules_farmier_csa_role_post_member",
                  "date" : [ "farmier-csa-user:field-csa-member-dates:value2" ],
                  "identifier" : "farmier_csa_end_membership_[farmier-csa-user:uid]",
                  "param_farmier_csa_user" : [ "farmier-csa-user" ]
                }
              }
            ],
            "LABEL" : "farmier_csa_reschedule_role_post_member"
          }
        },
        { "RULE" : {
            "IF" : [
              { "data_is_empty" : { "data" : [ "farmier-csa-user:field-csa-member-dates:value" ] } }
            ],
            "DO" : [
              { "schedule_delete" : {
                  "component" : "rules_farmier_csa_role_member",
                  "task" : "farmier_csa_begin_membership_[farmier-csa-user:uid]"
                }
              }
            ],
            "LABEL" : "farmier_csa_unschedule_role_member"
          }
        },
        { "RULE" : {
            "IF" : [
              { "data_is_empty" : { "data" : [ "farmier-csa-user:field-csa-member-dates:value2" ] } }
            ],
            "DO" : [
              { "schedule_delete" : {
                  "component" : "rules_farmier_csa_role_post_member",
                  "task" : "farmier_csa_end_membership_[farmier-csa-user:uid]"
                }
              }
            ],
            "LABEL" : "farmier_csa_unschedule_role_post_member"
          }
        }
      ]
    }
  }');
  $items['rules_farmier_csa_role_member'] = entity_import('rules_config', '{ "rules_farmier_csa_role_member" : {
      "LABEL" : "Farmier CSA Role Member",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "farmier_csa" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "farmier_csa_user" : { "label" : "User", "type" : "user" } },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "farmier-csa-user" ],
            "roles" : { "value" : { "173712484" : "173712484" } }
          }
        }
      ],
      "DO" : [
        { "user_remove_role" : {
            "account" : [ "farmier-csa-user" ],
            "roles" : { "value" : { "125843996" : "125843996", "196317508" : "196317508" } }
          }
        },
        { "user_add_role" : {
            "account" : [ "farmier-csa-user" ],
            "roles" : { "value" : { "173712484" : "173712484" } }
          }
        }
      ]
    }
  }');
  $items['rules_farmier_csa_role_post_member'] = entity_import('rules_config', '{ "rules_farmier_csa_role_post_member" : {
      "LABEL" : "Farmier CSA Role Post-Member",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "farmier_csa" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "farmier_csa_user" : { "label" : "User", "type" : "user" } },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "farmier-csa-user" ],
            "roles" : { "value" : { "196317508" : "196317508" } }
          }
        }
      ],
      "DO" : [
        { "user_remove_role" : {
            "account" : [ "farmier-csa-user" ],
            "roles" : { "value" : { "125843996" : "125843996", "173712484" : "173712484" } }
          }
        },
        { "user_add_role" : {
            "account" : [ "farmier-csa-user" ],
            "roles" : { "value" : { "196317508" : "196317508" } }
          }
        },
        { "data_set" : { "data" : [ "farmier-csa-user:field-csa-member-dates:value" ] } },
        { "data_set" : { "data" : [ "farmier-csa-user:field-csa-member-dates:value2" ] } }
      ]
    }
  }');
  $items['rules_farmier_csa_role_pre_member'] = entity_import('rules_config', '{ "rules_farmier_csa_role_pre_member" : {
      "LABEL" : "Farmier CSA Role Pre-Member",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "farmier_csa" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "farmier_csa_user" : { "label" : "User", "type" : "user" } },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "farmier-csa-user" ],
            "roles" : { "value" : { "125843996" : "125843996", "173712484" : "173712484" } }
          }
        }
      ],
      "DO" : [
        { "user_remove_role" : {
            "account" : [ "farmier-csa-user" ],
            "roles" : { "value" : { "196317508" : "196317508" } }
          }
        },
        { "user_add_role" : {
            "account" : [ "farmier-csa-user" ],
            "roles" : { "value" : { "125843996" : "125843996" } }
          }
        }
      ]
    }
  }');
  $items['rules_farmier_csa_update_member_end_date'] = entity_import('rules_config', '{ "rules_farmier_csa_update_member_end_date" : {
      "LABEL" : "Farmier CSA Update Member",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "farmier_csa" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_update" : [] },
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "account:field-csa-member-dates" ],
            "value" : [ "account-unchanged:field-csa-member-dates" ]
          }
        }
      ],
      "DO" : [
        { "component_rules_farmier_csa_reschedule_roles" : { "farmier_csa_user" : [ "account" ] } }
      ]
    }
  }');
  $items['rules_farmier_csa_update_product'] = entity_import('rules_config', '{ "rules_farmier_csa_update_product" : {
      "LABEL" : "Farmier CSA Update Product",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "farmier_csa" ],
      "REQUIRES" : [ "rules", "entity" ],
      "ON" : { "commerce_product_update" : [] },
      "IF" : [
        { "entity_has_field" : {
            "entity" : [ "commerce-product" ],
            "field" : "field_farmier_csa_date_range"
          }
        },
        { "OR" : [
            { "NOT data_is" : {
                "data" : [ "commerce-product:field-farmier-csa-date-range:value" ],
                "value" : [ "commerce-product-unchanged:field-farmier-csa-date-range:value" ]
              }
            },
            { "NOT data_is" : {
                "data" : [ "commerce-product:field-farmier-csa-date-range:value2" ],
                "value" : [ "commerce-product-unchanged:field-farmier-csa-date-range:value2" ]
              }
            }
          ]
        }
      ],
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "commerce_line_item",
              "property" : "commerce_product",
              "value" : [ "commerce-product:product-id" ],
              "limit" : "1000"
            },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "entity-fetched" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "component_rules_farmier_csa_product_line_item_membership" : { "line_item" : [ "list-item" ] } }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
