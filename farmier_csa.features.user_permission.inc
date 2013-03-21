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

  // Exported permission: assign CSA Member role.
  $permissions['assign CSA Member role'] = array(
    'name' => 'assign CSA Member role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: create commerce_product entities of bundle farmier_csa_subscription.
  $permissions['create commerce_product entities of bundle farmier_csa_subscription'] = array(
    'name' => 'create commerce_product entities of bundle farmier_csa_subscription',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: create field_csa_member_dates.
  $permissions['create field_csa_member_dates'] = array(
    'name' => 'create field_csa_member_dates',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: delete terms in csa_season.
  $permissions['delete terms in csa_season'] = array(
    'name' => 'delete terms in csa_season',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any commerce_product entity of bundle farmier_csa_subscription.
  $permissions['edit any commerce_product entity of bundle farmier_csa_subscription'] = array(
    'name' => 'edit any commerce_product entity of bundle farmier_csa_subscription',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit field_csa_member_dates.
  $permissions['edit field_csa_member_dates'] = array(
    'name' => 'edit field_csa_member_dates',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own commerce_product entities of bundle farmier_csa_subscription.
  $permissions['edit own commerce_product entities of bundle farmier_csa_subscription'] = array(
    'name' => 'edit own commerce_product entities of bundle farmier_csa_subscription',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: edit own field_csa_member_dates.
  $permissions['edit own field_csa_member_dates'] = array(
    'name' => 'edit own field_csa_member_dates',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit terms in csa_season.
  $permissions['edit terms in csa_season'] = array(
    'name' => 'edit terms in csa_season',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: view any commerce_product entity of bundle farmier_csa_subscription.
  $permissions['view any commerce_product entity of bundle farmier_csa_subscription'] = array(
    'name' => 'view any commerce_product entity of bundle farmier_csa_subscription',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view field_csa_member_dates.
  $permissions['view field_csa_member_dates'] = array(
    'name' => 'view field_csa_member_dates',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own commerce_product entities of bundle farmier_csa_subscription.
  $permissions['view own commerce_product entities of bundle farmier_csa_subscription'] = array(
    'name' => 'view own commerce_product entities of bundle farmier_csa_subscription',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: view own field_csa_member_dates.
  $permissions['view own field_csa_member_dates'] = array(
    'name' => 'view own field_csa_member_dates',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
