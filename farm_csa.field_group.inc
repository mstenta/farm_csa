<?php
/**
 * @file
 * farm_csa.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function farm_csa_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_farm_csa_prorate|commerce_product|farm_csa_subscription|form';
  $field_group->group_name = 'group_farm_csa_prorate';
  $field_group->entity_type = 'commerce_product';
  $field_group->bundle = 'farm_csa_subscription';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Share price prorating',
    'weight' => '5',
    'children' => array(
      0 => 'field_farm_csa_prorate',
      1 => 'field_farm_csa_prorate_type',
      2 => 'field_farm_csa_prorate_amount',
      3 => 'field_farm_csa_prorate_schedule',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Share price prorating',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-farm-csa-prorate field-group-fieldset',
        'description' => 'CSA subscription prices can be prorated on a regular basis during their season (the date range defined for each "CSA Subscription" product). Discounts can be a fixed amount or a percentage. The prorating schedule is defined with a repeating-date rule. Start by selecting the first date that a discount should be applied, and then specify when the next ones will by setting the repeating-date rules.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_farm_csa_prorate|commerce_product|farm_csa_subscription|form'] = $field_group;

  return $export;
}
