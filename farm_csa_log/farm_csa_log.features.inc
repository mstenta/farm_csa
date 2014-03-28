<?php
/**
 * @file
 * farm_csa_log.features.inc
 */

/**
 * Implements hook_default_log_type().
 */
function farm_csa_log_default_log_type() {
  $items = array();
  $items['farm_csa_member_cancel'] = entity_import('log_type', '{
    "type" : "farm_csa_member_cancel",
    "label" : "CSA Member: Cancel",
    "weight" : 0,
    "name_pattern" : "Cancel subscription: [log:field-farm-csa-subscription]",
    "rdf_mapping" : []
  }');
  $items['farm_csa_member_pause'] = entity_import('log_type', '{
    "type" : "farm_csa_member_pause",
    "label" : "CSA Member: Pause",
    "weight" : 0,
    "name_pattern" : "Pause subscription: [log:field-farm-csa-subscription]",
    "rdf_mapping" : []
  }');
  $items['farm_csa_member_subscribe'] = entity_import('log_type', '{
    "type" : "farm_csa_member_subscribe",
    "label" : "CSA Member: Subscribe",
    "weight" : 0,
    "name_pattern" : "[log:field-farm-customer:name] - [log:field-farm-csa-products]",
    "rdf_mapping" : []
  }');
  return $items;
}
