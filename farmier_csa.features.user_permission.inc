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

  // Exported permission: create farmier_csa_pickup content.
  $permissions['create farmier_csa_pickup content'] = array(
    'name' => 'create farmier_csa_pickup content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create field_csa_member_end_date.
  $permissions['create field_csa_member_end_date'] = array(
    'name' => 'create field_csa_member_end_date',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: delete any farmier_csa_pickup content.
  $permissions['delete any farmier_csa_pickup content'] = array(
    'name' => 'delete any farmier_csa_pickup content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own farmier_csa_pickup content.
  $permissions['delete own farmier_csa_pickup content'] = array(
    'name' => 'delete own farmier_csa_pickup content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
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

  // Exported permission: edit any farmier_csa_pickup content.
  $permissions['edit any farmier_csa_pickup content'] = array(
    'name' => 'edit any farmier_csa_pickup content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit field_csa_member_end_date.
  $permissions['edit field_csa_member_end_date'] = array(
    'name' => 'edit field_csa_member_end_date',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'field_permissions',
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

  // Exported permission: edit own farmier_csa_pickup content.
  $permissions['edit own farmier_csa_pickup content'] = array(
    'name' => 'edit own farmier_csa_pickup content',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own field_csa_member_end_date.
  $permissions['edit own field_csa_member_end_date'] = array(
    'name' => 'edit own field_csa_member_end_date',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'field_permissions',
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

  // Exported permission: view field_csa_member_end_date.
  $permissions['view field_csa_member_end_date'] = array(
    'name' => 'view field_csa_member_end_date',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'field_permissions',
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

  // Exported permission: view own field_csa_member_end_date.
  $permissions['view own field_csa_member_end_date'] = array(
    'name' => 'view own field_csa_member_end_date',
    'roles' => array(
      0 => 'administrator',
      1 => 'editor',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
