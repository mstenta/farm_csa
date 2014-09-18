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

  return $roles;
}
