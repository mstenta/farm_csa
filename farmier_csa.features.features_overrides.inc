<?php
/**
 * @file
 * farmier_csa.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function farmier_csa_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field
  $overrides["field.node-page-field_products.field_instance|settings|referenceable_types|farmier_csa_subscription"] = 'farmier_csa_subscription';

 return $overrides;
}
