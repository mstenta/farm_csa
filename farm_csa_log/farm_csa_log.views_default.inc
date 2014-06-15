<?php
/**
 * @file
 * farm_csa_log.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function farm_csa_log_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'farm_csa_subscriptions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'log';
  $view->human_name = 'Farm CSA Subscriptions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CSA Subscriptions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any log entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'field_farm_person' => 'field_farm_person',
    'field_farm_csa_products' => 'field_farm_csa_products',
    'field_farm_date_range' => 'field_farm_date_range',
    'field_farm_csa_order' => 'field_farm_csa_order',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_farm_person' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_farm_csa_products' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_farm_date_range' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_farm_csa_order' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No subscriptions found.';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_farm_person_target_id']['id'] = 'field_farm_person_target_id';
  $handler->display->display_options['relationships']['field_farm_person_target_id']['table'] = 'field_data_field_farm_person';
  $handler->display->display_options['relationships']['field_farm_person_target_id']['field'] = 'field_farm_person_target_id';
  $handler->display->display_options['relationships']['field_farm_person_target_id']['label'] = 'Person';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_farm_csa_products_target_id']['id'] = 'field_farm_csa_products_target_id';
  $handler->display->display_options['relationships']['field_farm_csa_products_target_id']['table'] = 'field_data_field_farm_csa_products';
  $handler->display->display_options['relationships']['field_farm_csa_products_target_id']['field'] = 'field_farm_csa_products_target_id';
  $handler->display->display_options['relationships']['field_farm_csa_products_target_id']['label'] = 'CSA Product';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '#';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Log: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Log: Person */
  $handler->display->display_options['fields']['field_farm_person']['id'] = 'field_farm_person';
  $handler->display->display_options['fields']['field_farm_person']['table'] = 'field_data_field_farm_person';
  $handler->display->display_options['fields']['field_farm_person']['field'] = 'field_farm_person';
  $handler->display->display_options['fields']['field_farm_person']['settings'] = array(
    'link' => 1,
  );
  /* Field: Log: CSA Product */
  $handler->display->display_options['fields']['field_farm_csa_products']['id'] = 'field_farm_csa_products';
  $handler->display->display_options['fields']['field_farm_csa_products']['table'] = 'field_data_field_farm_csa_products';
  $handler->display->display_options['fields']['field_farm_csa_products']['field'] = 'field_farm_csa_products';
  $handler->display->display_options['fields']['field_farm_csa_products']['label'] = 'Product';
  $handler->display->display_options['fields']['field_farm_csa_products']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_farm_csa_products']['delta_offset'] = '0';
  /* Field: Field: Date range */
  $handler->display->display_options['fields']['field_farm_date_range']['id'] = 'field_farm_date_range';
  $handler->display->display_options['fields']['field_farm_date_range']['table'] = 'field_data_field_farm_date_range';
  $handler->display->display_options['fields']['field_farm_date_range']['field'] = 'field_farm_date_range';
  $handler->display->display_options['fields']['field_farm_date_range']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Log: Order */
  $handler->display->display_options['fields']['field_farm_csa_order']['id'] = 'field_farm_csa_order';
  $handler->display->display_options['fields']['field_farm_csa_order']['table'] = 'field_data_field_farm_csa_order';
  $handler->display->display_options['fields']['field_farm_csa_order']['field'] = 'field_farm_csa_order';
  $handler->display->display_options['fields']['field_farm_csa_order']['settings'] = array(
    'link' => 1,
  );
  /* Filter criterion: Log: Log type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'log';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'farm_csa_member_subscribe' => 'farm_csa_member_subscribe',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'field_farm_person_target_id';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Person';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    125843996 => 0,
    173712484 => 0,
    196317508 => 0,
    146437786 => 0,
  );
  /* Filter criterion: Commerce Product: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_farm_csa_products_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Product search';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    125843996 => 0,
    173712484 => 0,
    196317508 => 0,
    146437786 => 0,
  );
  /* Filter criterion: Log: Order (field_farm_csa_order) */
  $handler->display->display_options['filters']['field_farm_csa_order_target_id']['id'] = 'field_farm_csa_order_target_id';
  $handler->display->display_options['filters']['field_farm_csa_order_target_id']['table'] = 'field_data_field_farm_csa_order';
  $handler->display->display_options['filters']['field_farm_csa_order_target_id']['field'] = 'field_farm_csa_order_target_id';
  $handler->display->display_options['filters']['field_farm_csa_order_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_farm_csa_order_target_id']['expose']['operator_id'] = 'field_farm_csa_order_target_id_op';
  $handler->display->display_options['filters']['field_farm_csa_order_target_id']['expose']['label'] = 'Order #';
  $handler->display->display_options['filters']['field_farm_csa_order_target_id']['expose']['description'] = 'Enter a specific order number.';
  $handler->display->display_options['filters']['field_farm_csa_order_target_id']['expose']['operator'] = 'field_farm_csa_order_target_id_op';
  $handler->display->display_options['filters']['field_farm_csa_order_target_id']['expose']['identifier'] = 'field_farm_csa_order_target_id';
  $handler->display->display_options['filters']['field_farm_csa_order_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
    200153887 => 0,
    125843996 => 0,
    173712484 => 0,
    196317508 => 0,
    146437786 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<p>Subscriptions are automatically created when a first payment is made to any order that contains subscription products.</p>

<p>To subscribe a new CSA member, follow these steps:</p>

<ol>
  <li><a href="/admin/people/create">Create a new user account</a> so that the customer can log into the website to see their order.</li>
  <li><a href="/admin/commerce/orders/add">Create a new order</a> assigned to that user account, and add one of your <a href="/admin/farm/csa/products">CSA Subscription products</a> to the order.</li>
  <li>Record a payment on the order, and a subscription will automatically appear in this list.</li>
</ol>

<p>You can delete subscriptions and/or regenerate them on an order-by-order basis. Click on an order # below to view that order, and then click on the "Subscriptions" tab in the top right.</p>

<p>You may narrow down the list of subscriptions using the fields below. Click "Apply" to apply the filter.</p>';
  $handler->display->display_options['path'] = 'admin/farm/csa/subscriptions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Subscriptions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'CSA';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Log: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Log: Person */
  $handler->display->display_options['fields']['field_farm_person']['id'] = 'field_farm_person';
  $handler->display->display_options['fields']['field_farm_person']['table'] = 'field_data_field_farm_person';
  $handler->display->display_options['fields']['field_farm_person']['field'] = 'field_farm_person';
  $handler->display->display_options['fields']['field_farm_person']['settings'] = array(
    'link' => 1,
  );
  /* Field: Log: CSA Product */
  $handler->display->display_options['fields']['field_farm_csa_products']['id'] = 'field_farm_csa_products';
  $handler->display->display_options['fields']['field_farm_csa_products']['table'] = 'field_data_field_farm_csa_products';
  $handler->display->display_options['fields']['field_farm_csa_products']['field'] = 'field_farm_csa_products';
  $handler->display->display_options['fields']['field_farm_csa_products']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_farm_csa_products']['delta_offset'] = '0';
  /* Field: Log: Order */
  $handler->display->display_options['fields']['field_farm_csa_order']['id'] = 'field_farm_csa_order';
  $handler->display->display_options['fields']['field_farm_csa_order']['table'] = 'field_data_field_farm_csa_order';
  $handler->display->display_options['fields']['field_farm_csa_order']['field'] = 'field_farm_csa_order';
  $handler->display->display_options['fields']['field_farm_csa_order']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Log: Log type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'log';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'farm_csa_member_subscribe' => 'farm_csa_member_subscribe',
  );
  $handler->display->display_options['link_to_view'] = '1';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Log: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'log';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;

  /* Display: Subscriptions by Order (Page) */
  $handler = $view->new_display('page', 'Subscriptions by Order (Page)', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'field_farm_person' => 'field_farm_person',
    'field_farm_csa_products' => 'field_farm_csa_products',
    'field_farm_date_range' => 'field_farm_date_range',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_farm_person' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_farm_csa_products' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_farm_date_range' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<p>Subscriptions are automatically created when a first payment is made to any order that contains subscription products.</p>

<p>For instructions on manually setting up a new subscription order, see the full <a href="/admin/farm/csa/subscriptions">CSA Subscriptions</a> list.</p>

<p>You can view, delete, and generate subscriptions for this specific order below.</p>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Log */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'log';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Subscription';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['skip_batching'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::panelizer_set_status_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Log: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'log';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Log: Person */
  $handler->display->display_options['fields']['field_farm_person']['id'] = 'field_farm_person';
  $handler->display->display_options['fields']['field_farm_person']['table'] = 'field_data_field_farm_person';
  $handler->display->display_options['fields']['field_farm_person']['field'] = 'field_farm_person';
  $handler->display->display_options['fields']['field_farm_person']['settings'] = array(
    'link' => 1,
  );
  /* Field: Log: CSA Product */
  $handler->display->display_options['fields']['field_farm_csa_products']['id'] = 'field_farm_csa_products';
  $handler->display->display_options['fields']['field_farm_csa_products']['table'] = 'field_data_field_farm_csa_products';
  $handler->display->display_options['fields']['field_farm_csa_products']['field'] = 'field_farm_csa_products';
  $handler->display->display_options['fields']['field_farm_csa_products']['label'] = 'Product';
  $handler->display->display_options['fields']['field_farm_csa_products']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_farm_csa_products']['delta_offset'] = '0';
  /* Field: Field: Date range */
  $handler->display->display_options['fields']['field_farm_date_range']['id'] = 'field_farm_date_range';
  $handler->display->display_options['fields']['field_farm_date_range']['table'] = 'field_data_field_farm_date_range';
  $handler->display->display_options['fields']['field_farm_date_range']['field'] = 'field_farm_date_range';
  $handler->display->display_options['fields']['field_farm_date_range']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Log: Order (field_farm_csa_order) */
  $handler->display->display_options['arguments']['field_farm_csa_order_target_id']['id'] = 'field_farm_csa_order_target_id';
  $handler->display->display_options['arguments']['field_farm_csa_order_target_id']['table'] = 'field_data_field_farm_csa_order';
  $handler->display->display_options['arguments']['field_farm_csa_order_target_id']['field'] = 'field_farm_csa_order_target_id';
  $handler->display->display_options['arguments']['field_farm_csa_order_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_farm_csa_order_target_id']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_farm_csa_order_target_id']['title'] = 'CSA Subscriptions for Order %1';
  $handler->display->display_options['arguments']['field_farm_csa_order_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_farm_csa_order_target_id']['default_argument_options']['index'] = '3';
  $handler->display->display_options['arguments']['field_farm_csa_order_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_farm_csa_order_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_farm_csa_order_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_farm_csa_order_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_farm_csa_order_target_id']['validate']['type'] = 'numeric';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Log: Log type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'log';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'farm_csa_member_subscribe' => 'farm_csa_member_subscribe',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/commerce/orders/%/subscriptions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Subscriptions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'CSA';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $export['farm_csa_subscriptions'] = $view;

  return $export;
}
