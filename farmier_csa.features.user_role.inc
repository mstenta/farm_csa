<?php
/**
 * @file
 * farmier_csa.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function farmier_csa_user_default_roles() {
  $roles = array();

  // Exported role: CSA Member.
  $roles['CSA Member'] = array(
    'name' => 'CSA Member',
    'weight' => '5',
  );

  // Exported role: CSA Post-Member.
  $roles['CSA Post-Member'] = array(
    'name' => 'CSA Post-Member',
    'weight' => '6',
  );

  // Exported role: CSA Pre-Member.
  $roles['CSA Pre-Member'] = array(
    'name' => 'CSA Pre-Member',
    'weight' => '4',
  );

  return $roles;
}
