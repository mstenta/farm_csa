<?php
/**
 * @file
 * farm_csa.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function farm_csa_user_default_roles() {
  $roles = array();

  // Exported role: CSA Member.
  $roles['CSA Member'] = array(
    'name' => 'CSA Member',
    'weight' => '5',
    'machine_name' => 'csa_member',
  );

  // Exported role: CSA Post-Member.
  $roles['CSA Post-Member'] = array(
    'name' => 'CSA Post-Member',
    'weight' => '6',
    'machine_name' => 'csa_post_member',
  );

  // Exported role: CSA Pre-Member.
  $roles['CSA Pre-Member'] = array(
    'name' => 'CSA Pre-Member',
    'weight' => '4',
    'machine_name' => 'csa_pre_member',
  );

  return $roles;
}
