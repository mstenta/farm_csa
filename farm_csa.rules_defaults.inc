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
  $items['rules_farm_csa_line_item_membership'] = entity_import('rules_config', '{ "rules_farm_csa_line_item_membership" : {
      "LABEL" : "Farm CSA Line Item Membership",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "farm_csa" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "farm_csa_user" : { "label" : "User", "type" : "user" },
        "farm_csa_line_item" : { "label" : "Line item", "type" : "commerce_line_item" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "farm-csa-line-item" ], "field" : "commerce_product" } },
        { "entity_has_field" : {
            "entity" : [ "farm-csa-line-item:commerce-product" ],
            "field" : "field_farm_csa_date_range"
          }
        },
        { "OR" : [
            { "data_is" : {
                "data" : [
                  "farm-csa-line-item:commerce-product:field-farm-csa-date-range:value2"
                ],
                "op" : "\\u003E",
                "value" : [ "farm-csa-user:field-csa-member-dates:value2" ]
              }
            },
            { "data_is_empty" : { "data" : [ "farm-csa-user:field-csa-member-dates" ] } }
          ]
        }
      ],
      "DO" : [
        { "component_rules_farm_csa_role_pre_member" : { "farm_csa_user" : [ "farm_csa_user" ] } },
        { "data_set" : {
            "data" : [ "farm-csa-user:field-csa-member-dates" ],
            "value" : [ "farm-csa-line-item:commerce-product:field-farm-csa-date-range" ]
          }
        },
        { "component_rules_farm_csa_reschedule_roles" : { "farm_csa_user" : [ "farm_csa_user" ] } }
      ]
    }
  }');
  $items['rules_farm_csa_payment'] = entity_import('rules_config', '{ "rules_farm_csa_payment" : {
      "LABEL" : "Farm CSA Payment",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "farm_csa" ],
      "REQUIRES" : [ "commerce_order", "rules", "entity" ],
      "ON" : { "commerce_payment_transaction_insert" : [] },
      "IF" : [
        { "commerce_order_contains_product_type" : {
            "commerce_order" : [ "commerce-payment-transaction:order" ],
            "product_type" : { "value" : { "farm_csa_subscription" : "farm_csa_subscription" } },
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
              { "component_rules_farm_csa_line_item_membership" : {
                  "farm_csa_user" : [ "commerce-payment-transaction:order:owner" ],
                  "farm_csa_line_item" : [ "list-item" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_farm_csa_product_line_item_membership'] = entity_import('rules_config', '{ "rules_farm_csa_product_line_item_membership" : {
      "LABEL" : "Farm CSA Product Line Item Membership",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "farm_csa" ],
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
        { "component_rules_farm_csa_line_item_membership" : {
            "farm_csa_user" : [ "order-owner" ],
            "farm_csa_line_item" : [ "line-item" ]
          }
        }
      ]
    }
  }');
  $items['rules_farm_csa_reschedule_roles'] = entity_import('rules_config', '{ "rules_farm_csa_reschedule_roles" : {
      "LABEL" : "Farm CSA Reschedule Roles",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "TAGS" : [ "farm_csa" ],
      "REQUIRES" : [ "rules", "rules_scheduler" ],
      "USES VARIABLES" : { "farm_csa_user" : { "label" : "Farm CSA User", "type" : "user" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "NOT data_is_empty" : { "data" : [ "farm-csa-user:field-csa-member-dates:value" ] } }
            ],
            "DO" : [
              { "schedule" : {
                  "component" : "rules_farm_csa_role_member",
                  "date" : [ "farm-csa-user:field-csa-member-dates:value" ],
                  "identifier" : "farm_csa_begin_membership_[farm-csa-user:uid]",
                  "param_farm_csa_user" : [ "farm-csa-user" ]
                }
              }
            ],
            "LABEL" : "farm_csa_reschedule_role_member"
          }
        },
        { "RULE" : {
            "IF" : [
              { "NOT data_is_empty" : { "data" : [ "farm-csa-user:field-csa-member-dates:value2" ] } }
            ],
            "DO" : [
              { "schedule" : {
                  "component" : "rules_farm_csa_role_post_member",
                  "date" : [ "farm-csa-user:field-csa-member-dates:value2" ],
                  "identifier" : "farm_csa_end_membership_[farm-csa-user:uid]",
                  "param_farm_csa_user" : [ "farm-csa-user" ]
                }
              }
            ],
            "LABEL" : "farm_csa_reschedule_role_post_member"
          }
        },
        { "RULE" : {
            "IF" : [
              { "data_is_empty" : { "data" : [ "farm-csa-user:field-csa-member-dates:value" ] } }
            ],
            "DO" : [
              { "schedule_delete" : {
                  "component" : "rules_farm_csa_role_member",
                  "task" : "farm_csa_begin_membership_[farm-csa-user:uid]"
                }
              }
            ],
            "LABEL" : "farm_csa_unschedule_role_member"
          }
        },
        { "RULE" : {
            "IF" : [
              { "data_is_empty" : { "data" : [ "farm-csa-user:field-csa-member-dates:value2" ] } }
            ],
            "DO" : [
              { "schedule_delete" : {
                  "component" : "rules_farm_csa_role_post_member",
                  "task" : "farm_csa_end_membership_[farm-csa-user:uid]"
                }
              }
            ],
            "LABEL" : "farm_csa_unschedule_role_post_member"
          }
        }
      ]
    }
  }');
  $items['rules_farm_csa_role_member'] = entity_import('rules_config', '{ "rules_farm_csa_role_member" : {
      "LABEL" : "Farm CSA Role Member",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "farm_csa" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "farm_csa_user" : { "label" : "User", "type" : "user" } },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "farm-csa-user" ],
            "roles" : { "value" : { "173712484" : "173712484" } }
          }
        }
      ],
      "DO" : [
        { "user_remove_role" : {
            "account" : [ "farm-csa-user" ],
            "roles" : { "value" : { "125843996" : "125843996", "196317508" : "196317508" } }
          }
        },
        { "user_add_role" : {
            "account" : [ "farm-csa-user" ],
            "roles" : { "value" : { "173712484" : "173712484" } }
          }
        }
      ]
    }
  }');
  $items['rules_farm_csa_role_post_member'] = entity_import('rules_config', '{ "rules_farm_csa_role_post_member" : {
      "LABEL" : "Farm CSA Role Post-Member",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "farm_csa" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "farm_csa_user" : { "label" : "User", "type" : "user" } },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "farm-csa-user" ],
            "roles" : { "value" : { "196317508" : "196317508" } }
          }
        }
      ],
      "DO" : [
        { "user_remove_role" : {
            "account" : [ "farm-csa-user" ],
            "roles" : { "value" : { "125843996" : "125843996", "173712484" : "173712484" } }
          }
        },
        { "user_add_role" : {
            "account" : [ "farm-csa-user" ],
            "roles" : { "value" : { "196317508" : "196317508" } }
          }
        },
        { "data_set" : { "data" : [ "farm-csa-user:field-csa-member-dates:value" ] } },
        { "data_set" : { "data" : [ "farm-csa-user:field-csa-member-dates:value2" ] } }
      ]
    }
  }');
  $items['rules_farm_csa_role_pre_member'] = entity_import('rules_config', '{ "rules_farm_csa_role_pre_member" : {
      "LABEL" : "Farm CSA Role Pre-Member",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "farm_csa" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "farm_csa_user" : { "label" : "User", "type" : "user" } },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "farm-csa-user" ],
            "roles" : { "value" : { "125843996" : "125843996", "173712484" : "173712484" } }
          }
        }
      ],
      "DO" : [
        { "user_remove_role" : {
            "account" : [ "farm-csa-user" ],
            "roles" : { "value" : { "196317508" : "196317508" } }
          }
        },
        { "user_add_role" : {
            "account" : [ "farm-csa-user" ],
            "roles" : { "value" : { "125843996" : "125843996" } }
          }
        }
      ]
    }
  }');
  $items['rules_farm_csa_update_member_end_date'] = entity_import('rules_config', '{ "rules_farm_csa_update_member_end_date" : {
      "LABEL" : "Farm CSA Update Member",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "farm_csa" ],
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
        { "component_rules_farm_csa_reschedule_roles" : { "farm_csa_user" : [ "account" ] } }
      ]
    }
  }');
  $items['rules_farm_csa_update_product'] = entity_import('rules_config', '{ "rules_farm_csa_update_product" : {
      "LABEL" : "Farm CSA Update Product",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "farm_csa" ],
      "REQUIRES" : [ "rules", "entity" ],
      "ON" : { "commerce_product_update" : [] },
      "IF" : [
        { "entity_has_field" : {
            "entity" : [ "commerce-product" ],
            "field" : "field_farm_csa_date_range"
          }
        },
        { "OR" : [
            { "NOT data_is" : {
                "data" : [ "commerce-product:field-farm-csa-date-range:value" ],
                "value" : [ "commerce-product-unchanged:field-farm-csa-date-range:value" ]
              }
            },
            { "NOT data_is" : {
                "data" : [ "commerce-product:field-farm-csa-date-range:value2" ],
                "value" : [ "commerce-product-unchanged:field-farm-csa-date-range:value2" ]
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
              { "component_rules_farm_csa_product_line_item_membership" : { "line_item" : [ "list-item" ] } }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
