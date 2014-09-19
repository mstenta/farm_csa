<?php
/**
 * @file
 * Farm CSA Rules integration
 */

/**
 * Implements hook_rules_action_info().
 */
function farm_csa_rules_action_info() {

  // Define an action for prorating a product.
  $actions['farm_csa_rules_action_prorate'] = array(
    'label' => t('Prorate CSA share price'),
    'parameter' => array(
      'commerce_line_item' => array(
        'type' => 'commerce_line_item',
        'label' => t('Line item'),
      ),
      'round_mode' => array(
        'type' => 'integer',
        'label' => t('Price rounding mode'),
        'description' => t('Round the resulting price amount after performing this operation.'),
        'options list' => 'commerce_round_mode_options_list',
        'default value' => COMMERCE_ROUND_HALF_UP,
      ),
    ),
    'group' => t('Farm CSA'),
  );

  return $actions;
}

/**
 * Rules action: prorate a product based on prorating configuration options.
 * Copied and modified from commerce_line_item_unit_price_subtract().
 */
function farm_csa_rules_action_prorate($line_item, $round_mode) {

  // Only proceed if the line item has a product associated with it.
  if (empty($line_item->commerce_product[LANGUAGE_NONE][0]['product_id'])) {
    return;
  }

  // Load the product.
  $product = commerce_product_load($line_item->commerce_product[LANGUAGE_NONE][0]['product_id']);

  // If the product isn't a CSA Subscription, bail.
  if ($product->type != 'farm_csa_subscription') {
    return;
  }

  // If prorating is disabled, or the amount is zero, bail.
  if (empty($product->field_farm_csa_prorate[LANGUAGE_NONE][0]['value']) || empty($product->field_farm_csa_prorate_amount[LANGUAGE_NONE][0]['value'])) {
    return;
  }

  // If the prorating schedule is not valid, bail.
  $schedules = array(
    'daily',
    'weekly',
    'monthly',
  );
  if (empty($product->field_farm_csa_prorate_schedule[LANGUAGE_NONE][0]['value']) || !in_array($product->field_farm_csa_prorate_schedule[LANGUAGE_NONE][0]['value'], $schedules)) {
    return;
  }

  // If the prorating type is not valid, bail.
  $types = array(
    'percent',
    'fixed',
  );
  if (empty($product->field_farm_csa_prorate_type[LANGUAGE_NONE][0]['value']) || !in_array($product->field_farm_csa_prorate_type[LANGUAGE_NONE][0]['value'], $types)) {
    return;
  }

  // Load the configuration variables.
  $prorate_amount = $product->field_farm_csa_prorate_amount[LANGUAGE_NONE][0]['value'];
  $prorate_type = $product->field_farm_csa_prorate_type[LANGUAGE_NONE][0]['value'];
  $prorate_schedule = $product->field_farm_csa_prorate_schedule[LANGUAGE_NONE][0]['value'];

  // If the product doesn't have a valid date range, bail.
  if (empty($product->field_farm_date_range[LANGUAGE_NONE][0]['value']) || empty($product->field_farm_date_range[LANGUAGE_NONE][0]['value2'])) {
    return;
  }

  // Load the share's date range.
  $start_date = $product->field_farm_date_range[LANGUAGE_NONE][0]['value'];
  $end_date = $product->field_farm_date_range[LANGUAGE_NONE][0]['value2'];

  // If the current time does not fall between the range, bail.
  if (REQUEST_TIME < $start_date || REQUEST_TIME > $end_date) {
    return;
  }

  // Get the unit price of the line item.
  $unit_price = $line_item->commerce_unit_price[LANGUAGE_NONE][0]['amount'];

  // If the unit price is already zero, bail.
  if (empty($unit_price)) {
    return;
  }

  // If the prorating type is 'percent', calculate the value as a percentage
  // of the original line item unit price.
  $amount = 0;
  if ($prorate_type == 'percent') {
    $amount = ($prorate_amount / 100) * $unit_price;
  }

  // Or, if the prorating type is 'fixed', convert the value to an integer for Commerce.
  elseif ($prorate_type == 'fixed') {
    $amount = commerce_currency_decimal_to_amount($prorate_amount, commerce_default_currency());
  }

  // Based on the schedule, determine how many discounts should be applied.
  // Count how many days/weeks/months have passed since the start date.
  $day = 60 * 60 * 24;
  $week = $day * 7;
  $month = $week * 4;
  $time_passed = REQUEST_TIME - $start_date;
  $iterations = 0;
  switch ($prorate_schedule) {
    case 'daily':
      $iterations = $time_passed / $day;
      break;
    case 'weekly':
      $iterations = $time_passed / $week;
      break;
    case 'monthly':
      $iterations = $time_passed / $month;
      break;
  }

  // Round the number of iterations down to a whole number.
  $iterations = floor($iterations);

  // Multiply the amount by the discount number of iterations that have passed.
  $amount = $amount * $iterations;

  // If the resulting price is negative, something must be wrong... bail!
  if ($unit_price - $amount < 0) {
    return;
  }

  // This will be acting on the 'discount' price component.
  $component_name = 'discount';

  // Call out to the commerce_line_item_unit_price_subtract() function
  // to perform the discounting.
  module_load_include('inc', 'commerce_line_item', 'commerce_line_item.rules');
  commerce_line_item_unit_price_subtract($line_item, $amount, $component_name, $round_mode);
}
