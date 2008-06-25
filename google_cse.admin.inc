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
    '#title' => t('Google Custom Search Engine ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('google_cse_cx', ''),
    '#description' => t('Enter your alphanumeric <a target="_blank" href="http://www.google.com/coop/manage/cse/">Google Custom Search Engine ID</a>. Click on control panel and then click on code. The only part you need is the <em>cx</em> value.'),
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
    '#description' => t('Enter a custom title of the page where search results are displayed (defaults to %search).', array('%search' => t('Search'))),
    '#default_value' => variable_get('google_cse_results_title', ''),
  );
  $form['google_cse_results_tab'] = array(
    '#title' => t('Search results tab name'),
    '#type' => 'textfield',
    '#maxlength' => 50,
    '#size' => 60, 
    '#description' => t('Enter a custom name of the tab where search results are displayed (defaults to %google). The tab only appears if the Search module is enabled.', array('%google' => t('Google'))),
    '#default_value' => variable_get('google_cse_results_tab', ''),
  );
  $form['google_cse_sitesearch'] = array(
    '#title' => t('SiteSearch domain'),
    '#type' => 'textfield',
    '#maxlength' => 50,
    '#size' => 60, 
    '#description' => t('If set, users will be presented with the option of searching only on the domain specified rather than using the CSE.'),
    '#default_value' => variable_get('google_cse_sitesearch', ''),
  );
  $form['google_cse_sitesearch_default'] = array(
    '#title' => t('Default to using the SiteSearch domain'),
    '#type' => 'checkbox',
    '#description' => t('If set, searches will default to using the SiteSearch domain rather than the CSE.'),
    '#default_value' => variable_get('google_cse_sitesearch_default', 0),
  );
  $form['google_cse_cof_here'] = array(
    '#title' => t('Ad format on this site'),
    '#type' => 'radios',
    '#default_value' => variable_get('google_cse_cof_here', 'FORID:11'),
    '#options' => array(
      'FORID:9' => t('Right'),
      'FORID:10' => t('Top and right'),
      'FORID:11' => t('Top and bottom'),
    ),
    '#description' => t('Ads on the right increase the width of the iframe. Non-profit organizations can disable ads in the Google CSE control panel.'),
  );
  $form['google_cse_cof_google'] = array(
    '#title' => t('Ad format on Google'),
    '#type' => 'radios',
    '#default_value' => variable_get('google_cse_cof_google', 'FORID:0'),
    '#options' => array(
      'FORID:0' => t('Right'),
      'FORID:1' => t('Top and bottom'),
    ),
    '#description' => t('AdSense ads are also displayed when the CSE links or redirects to Google.'),
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
    '#type' => 'checkbox',
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
  $form['advanced'] = array(
    '#title' => t('Advanced settings'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['advanced']['google_cse_cr'] = array(
    '#title' => t('Country restriction'),
    '#type' => 'textfield',
    '#default_value' => variable_get('google_cse_cr', ''), 
    '#description' => t('Enter a 9-letter country code, e.g. <em>countryNZ</em>, and optional boolean operators, to restrict search results to documents (not) originating in particular countries. See the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#crsp"><em>cr</em> parameter</a>.'),
  );
  $form['advanced']['google_cse_gl'] = array(
    '#title' => t('Country boost'),
    '#type' => 'textfield',
    '#default_value' => variable_get('google_cse_gl', ''), 
    '#description' => t('Enter a 2-letter country code, e.g. <em>uk</em>, to boost documents written in a particular country. See the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#glsp"><em>gl</em> parameter</a>.'),
  );
  $form['advanced']['google_cse_hl'] = array(
    '#title' => t('Interface language'),
    '#type' => 'textfield',
    '#default_value' => variable_get('google_cse_hl', ''), 
    '#description' => t('Enter a supported 2- or 5-character language code, e.g. <em>fr</em>, to set the language of the user interface. See the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#hlsp"><em>hl</em> parameter</a>.'),
  );
  $form['advanced']['google_cse_locale_hl'] = array(
    '#title' => t('Set interface language dynamically'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('google_cse_locale_hl', ''), 
    '#description' => t('The language restriction can be set dynamically if the locale module is enabled. Note the locale language code must match one of the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#interfaceLanguages">supported language codes</a>.'),
  );
  $form['advanced']['google_cse_ie'] = array(
    '#title' => t('Input encoding'),
    '#type' => 'textfield',
    '#default_value' => variable_get('google_cse_ie', ''), 
    '#description' => t('The default <em>utf8</em> is recommended. See the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#iesp"><em>ie</em> parameter</a>.'),
  );
  $form['advanced']['google_cse_lr'] = array(
    '#title' => t('Language restriction'),
    '#type' => 'textfield',
    '#default_value' => variable_get('google_cse_lr', ''), 
    '#description' => t('Enter a supported 7- or 10-character language code, e.g. <em>lang_en</em>, and optional boolean operators, to restrict search results to documents (not) written in particular languages. See the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#lrsp"><em>lr</em> parameter</a>.'),
  );
  $form['advanced']['google_cse_locale_lr'] = array(
    '#title' => t('Set language restriction dynamically'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('google_cse_locale_lr', ''), 
    '#description' => t('The language restriction can be set dynamically if the locale module is enabled. Note the locale language code must match one of the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#languageCollections">supported language codes</a>.'),
  );
  $form['advanced']['google_cse_oe'] = array(
    '#title' => t('Output encoding'),
    '#type' => 'textfield',
    '#default_value' => variable_get('google_cse_oe', ''), 
    '#description' => t('The default <em>utf8</em> is recommended. See the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#oesp"><em>oe</em> parameter</a>.'),
  );
  $form['advanced']['google_cse_safe'] = array(
    '#title' => t('SafeSearch filter'),
    '#type' => 'select',
    '#options' => array('' => '', 'off' => t('Off'), 'medium' => t('Medium'), 'high' => t('High')),
    '#default_value' => variable_get('google_cse_safe', ''), 
    '#description' => t('SafeSearch filters search results for adult content. See the <a target="_blank" href="http://www.google.com/coop/docs/cse/resultsxml.html#safesp"><em>safe</em> parameter</a>.'),
  );
  return system_settings_form($form);
}
