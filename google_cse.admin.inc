<?php
// $Id$

/**
 * @file
 * Admin settings for Google Custom Search Engine.
 */

/**
 * Admin settings page for the CSE.
 */
function google_cse_admin_settings() {
  $form = array();
  $form['google_cse_cx'] = array(
    '#title' => t('Google Co-op Custom Search Engine ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('google_cse_cx', ''),
    '#description' => t('Enter your <a target="_blank" href="http://www.google.com/coop/cse">Google Co-op Custom Search Engine ID</a>.'),
  );
  $form['google_cse_results_display'] = array(
    '#title' => t('Display search results'),
    '#type' => 'radios',
    '#default_value' => variable_get('google_cse_results_display', 'here'),
    '#options' => array(
      'here' => t('On this site (requires JavaScript)'),
      'google' => t('On Google'),
    ),
    '#description' => t('Search results can be displayed on this site, using JavaScript, or on Google, which does not require JavaScript. Note: You can also configure your CSE at Google to have the iGoogle widget point to your site, but <strong>that will not work</strong> (see below). This setting only affects your own searchbox.'),
  );
  $form['google_cse_results_title'] = array(
    '#title' => t('Search results page title'),
    '#type' => 'textfield',
    '#maxlength' => 50,
    '#size' => 60, 
    '#description' => t('Enter the desired title of the page where the search results will be displayed. This has no effect if you do not display results on your own site.'),
    '#default_value' => variable_get('google_cse_results_title', t('Search')),
  );
  $form['google_cse_searchbox_width'] = array(
    '#title' => t('Searchbox width'),
    '#type' => 'textfield',
    '#maxlength' => 4,
    '#size' => 6, 
    '#description' => t('Enter the desired width, in characters, of the searchbox when displayed in a block.'),
    '#default_value' => variable_get('google_cse_searchbox_width', 15),
  );
  $form['google_cse_results_searchbox_width'] = array(
    '#title' => t('Search results searchbox width'),
    '#type' => 'textfield',
    '#maxlength' => 4,
    '#size' => 6, 
    '#description' => t('Enter the desired width, in characters, of the searchbox when displayed on the results page.'),
    '#default_value' => variable_get('google_cse_results_searchbox_width', 40),
  );
  $form['google_cse_results_width'] = array(
    '#title' => t('Search results frame width'),
    '#type' => 'textfield',
    '#maxlength' => 4,
    '#size' => 6, 
    '#description' => t('Enter the desired width, in pixels, of the search frame.'),
    '#default_value' => variable_get('google_cse_results_width', 600),
  );
  $form['google_cse_results_gadget'] = array(
    '#title' => t('Search results "Add to Google" Google Gadget'),
    '#type' => 'radios',
    '#options' => array(t('Disabled'), t('Enabled')),
    '#default_value' => variable_get('google_cse_results_gadget', 1),
    '#description' => t('If enabled, an "Add to Google" button will be displayed above the search results. For this to function, you must <strong>not</strong> have <a target="_blank" href="http://www.google.com/coop/manage/cse/">configured</a> your CSE results to appear on this site, because Drupal sites are not compatible with the "q" parameter. Search results will still appear on this site for searches originating here.'),
  );
  $form['google_cse_domain'] = array(
    '#title' => t('Search domain'),
    '#type' => 'textfield',
    '#maxlength' => 64,
    '#description' => t('Enter the Google domain to use for search results, e.g. <em>www.google.com</em>.'),
    '#default_value' => variable_get('google_cse_domain', 'www.google.com'),
  );
  return system_settings_form($form);
}
