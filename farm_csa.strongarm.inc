<?php
/**
 * @file
 * farm_csa.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function farm_csa_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_farm_csa_date';
  $strongarm->value = 'M jS, Y';
  $export['date_format_farm_csa_date'] = $strongarm;

  return $export;
}
