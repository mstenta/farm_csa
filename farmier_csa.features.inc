<?php
/**
 * @file
 * farmier_csa.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function farmier_csa_commerce_product_default_types() {
  $items = array(
    'farmier_csa_subscription' => array(
      'type' => 'farmier_csa_subscription',
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
function farmier_csa_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
