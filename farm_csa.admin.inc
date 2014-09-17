<?php
/**
 * @file
 * Farm CSA admin pages.
 */

/**
 * Farm CSA administrative settings form.
 */
function farm_csa_settings_form($form, &$form_state) {

  // Prorating fieldset.
  $form['prorate'] = array(
    '#type' => 'fieldset',
    '#title' => t('Share price prorating'),
    '#description' => t('CSA subscription prices can be prorated on a regular basis during their season (the date range defined for each "CSA Subscription" product). Discounts can be a fixed amount or a percentage, and can be applied daily, weekly, or monthly during the effective dates of the subscription.'),
  );

  // Checkbox to enable/disable pro-rating.
  $form['prorate']['farm_csa_prorate'] = array(
    '#type' => 'checkbox',
    '#title' => t('Prorate share prices during the season.'),
    '#default_value' => variable_get('farm_csa_prorate', FALSE),
  );

  // Prorate schedule (day/week/month)
  $form['prorate']['farm_csa_prorate_schedule'] = array(
    '#type' => 'select',
    '#title' => t('Prorate schedule'),
    '#description' => t('At what interval should discounts be applied?'),
    '#options' => array(
      'daily' => t('Daily'),
      'weekly' => t('Weekly'),
      'monthly' => t('Monthly'),
    ),
    '#default_value' => variable_get('farm_csa_prorate_schedule', 'weekly'),
  );

  // Text field to collect the discount amount.
  $form['prorate']['farm_csa_prorate_amount'] = array(
    '#type' => 'textfield',
    '#title' => t('Discount amount'),
    '#description' => t('This is the amount of the discount (fixed or percentage) that will be applied each day/week/month during the product\'s date range.'),
    '#default_value' => variable_get('farm_csa_prorate_amount', 0),
    '#element_validate' => array('element_validate_number'),
  );

  // Type of prorate (fixed or percentage).
  $form['prorate']['farm_csa_prorate_type'] = array(
    '#type' => 'select',
    '#title' => t('Fixed or percentage'),
    '#description' => t('Should the discount amount be treated as a fixed amount or a percentage of the product\'s original price?'),
    '#options' => array(
      'fixed' => t('Fixed'),
      'percent' => t('Percentage'),
    ),
    '#default_value' => variable_get('farm_csa_prorate_type', 'percent'),
  );

  // Return the form as a system settings form.
  return system_settings_form($form);
}
