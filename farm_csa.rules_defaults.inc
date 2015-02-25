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
  $items['rules_farm_csa_prorate_share_prices'] = entity_import('rules_config', '{ "rules_farm_csa_prorate_share_prices" : {
      "LABEL" : "Farm CSA Prorate Share Prices",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "farm_csa", "commerce_product_reference" ],
      "ON" : { "commerce_product_calculate_sell_price" : [] },
      "DO" : [
        { "farm_csa_rules_action_prorate" : { "commerce_line_item" : [ "commerce_line_item" ], "round_mode" : "1" } }
      ]
    }
  }');
  return $items;
}
