<?php
/**
 * @file
 * farm_csa.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function farm_csa_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'farm_csa_admin';
  $page->task = 'page';
  $page->admin_title = 'Farm CSA Admin';
  $page->admin_description = 'Administrative interface for the CSA.';
  $page->path = 'admin/farm/csa/overview';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'edit any commerce_product entity of bundle farm_csa_subscription',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'default tab',
    'title' => 'Overview',
    'name' => 'navigation',
    'weight' => '-10',
    'parent' => array(
      'type' => 'tab',
      'title' => 'CSA',
      'name' => 'management',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_farm_csa_admin_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'farm_csa_admin';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Farm CSA';
  $display->uuid = 'f65f1256-87c1-4082-aa15-8fc0ef0647f5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8f780d97-75fb-4b09-9de8-0ef7bdeb8d61';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Description',
      'title' => '',
      'body' => 'Manage the CSA using the tabs above.',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8f780d97-75fb-4b09-9de8-0ef7bdeb8d61';
    $display->content['new-8f780d97-75fb-4b09-9de8-0ef7bdeb8d61'] = $pane;
    $display->panels['middle'][0] = 'new-8f780d97-75fb-4b09-9de8-0ef7bdeb8d61';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8f780d97-75fb-4b09-9de8-0ef7bdeb8d61';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['farm_csa_admin'] = $page;

  return $pages;

}
