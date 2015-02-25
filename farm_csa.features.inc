<?php
/**
 * @file
 * farm_csa.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function farm_csa_commerce_product_default_types() {
  $items = array(
    'farm_csa_subscription' => array(
      'type' => 'farm_csa_subscription',
      'name' => 'CSA Subscription',
      'description' => 'A product type for selling CSA subscriptions.',
      'help' => '',
      'revision' => '1',
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function farm_csa_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function farm_csa_views_api() {
  return array("version" => "3.0");
}
