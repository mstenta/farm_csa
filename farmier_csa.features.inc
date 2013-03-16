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

/**
 * Implements hook_views_api().
 */
function farmier_csa_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_field_default_fields_alter().
 */
function farmier_csa_field_default_fields_alter(&$data) {
  if (isset($data['node-page-field_products'])) {
    $data['node-page-field_products']['field_instance']['settings']['referenceable_types']['commerce_sp_subscription'] = 0; /* WAS: '' */
    $data['node-page-field_products']['field_instance']['settings']['referenceable_types']['farmier_csa_subscription'] = 'farmier_csa_subscription'; /* WAS: '' */
  }
}

/**
 * Implements hook_node_info().
 */
function farmier_csa_node_info() {
  $items = array(
    'pickup' => array(
      'name' => t('CSA Pickup Location'),
      'base' => 'node_content',
      'description' => t('Use <em>CSA Pickup Locations</em> to create new locations where customers can pick up their shares.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
