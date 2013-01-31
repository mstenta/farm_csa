<?php
/**
 * @file
 * farmier_csa.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function farmier_csa_user_default_permissions() {
  $permissions = array();

  // Exported permission: create commerce_product entities of bundle farmier_csa_subscription.
  $permissions['create commerce_product entities of bundle farmier_csa_subscription'] = array(
    'name' => 'create commerce_product entities of bundle farmier_csa_subscription',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit any commerce_product entity of bundle farmier_csa_subscription.
  $permissions['edit any commerce_product entity of bundle farmier_csa_subscription'] = array(
    'name' => 'edit any commerce_product entity of bundle farmier_csa_subscription',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own commerce_product entities of bundle farmier_csa_subscription.
  $permissions['edit own commerce_product entities of bundle farmier_csa_subscription'] = array(
    'name' => 'edit own commerce_product entities of bundle farmier_csa_subscription',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view any commerce_product entity of bundle farmier_csa_subscription.
  $permissions['view any commerce_product entity of bundle farmier_csa_subscription'] = array(
    'name' => 'view any commerce_product entity of bundle farmier_csa_subscription',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own commerce_product entities of bundle farmier_csa_subscription.
  $permissions['view own commerce_product entities of bundle farmier_csa_subscription'] = array(
    'name' => 'view own commerce_product entities of bundle farmier_csa_subscription',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'commerce_product',
  );

  return $permissions;
}
