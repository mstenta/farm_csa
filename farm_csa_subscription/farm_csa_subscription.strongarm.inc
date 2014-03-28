<?php
/**
 * @file
 * farm_csa_subscription.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function farm_csa_subscription_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_commerce_product__farm_csa_subscription';
  $strongarm->value = array(
    'view_modes' => array(
      'line_item' => array(
        'custom_settings' => TRUE,
      ),
      'node_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'commerce_line_item_display' => array(
        'custom_settings' => FALSE,
      ),
      'commerce_line_item_diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'commerce_line_item_token' => array(
        'custom_settings' => FALSE,
      ),
      'node_full' => array(
        'custom_settings' => FALSE,
      ),
      'node_rss' => array(
        'custom_settings' => FALSE,
      ),
      'node_diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'node_token' => array(
        'custom_settings' => FALSE,
      ),
      'node_email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'node_email_html' => array(
        'custom_settings' => FALSE,
      ),
      'node_email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'taxonomy_term_full' => array(
        'custom_settings' => FALSE,
      ),
      'taxonomy_term_diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'taxonomy_term_token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'sku' => array(
          'weight' => '0',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'status' => array(
          'weight' => '8',
        ),
        'metatags' => array(
          'weight' => '9',
        ),
        'redirect' => array(
          'weight' => '10',
        ),
      ),
      'display' => array(
        'sku' => array(
          'line_item' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'title' => array(
          'line_item' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'status' => array(
          'line_item' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_commerce_product__farm_csa_subscription'] = $strongarm;

  return $export;
}
