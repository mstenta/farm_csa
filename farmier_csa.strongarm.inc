<?php
/**
 * @file
 * farmier_csa.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function farmier_csa_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_farmier_csa_pickup';
  $strongarm->value = 'edit-xmlsitemap';
  $export['additional_settings__active_tab_farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_farmier_csa_pickup';
  $strongarm->value = '0';
  $export['comment_anonymous_farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_farmier_csa_pickup';
  $strongarm->value = 1;
  $export['comment_default_mode_farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_farmier_csa_pickup';
  $strongarm->value = '50';
  $export['comment_default_per_page_farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_farmier_csa_pickup';
  $strongarm->value = '1';
  $export['comment_farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_farmier_csa_pickup';
  $strongarm->value = 1;
  $export['comment_form_location_farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_farmier_csa_pickup';
  $strongarm->value = '1';
  $export['comment_preview_farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_farmier_csa_pickup';
  $strongarm->value = 1;
  $export['comment_subject_field_farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_farmier_csa_date';
  $strongarm->value = 'M jS, Y';
  $export['date_format_farmier_csa_date'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_commerce_product__farmier_csa_subscription';
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
          'weight' => '7',
        ),
        'metatags' => array(
          'weight' => '8',
        ),
        'redirect' => array(
          'weight' => '9',
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
            'weight' => '6',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_commerce_product__farmier_csa_subscription'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__farmier_csa_pickup';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '4',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '5',
        ),
        'redirect' => array(
          'weight' => '6',
        ),
        'xmlsitemap' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_farmier_csa_pickup';
  $strongarm->value = array();
  $export['menu_options_farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_farmier_csa_pickup';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_farmier_csa_pickup';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_farmier_csa_pickup';
  $strongarm->value = '0';
  $export['node_preview_farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_farmier_csa_pickup';
  $strongarm->value = 0;
  $export['node_submitted_farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_farmier_csa_pickup_pattern';
  $strongarm->value = 'csa/pickup/[node:title]';
  $export['pathauto_node_farmier_csa_pickup_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_farmier_csa_pickup';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_farmier_csa_pickup'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_farmier_csa_pickup';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_farmier_csa_pickup'] = $strongarm;

  return $export;
}
