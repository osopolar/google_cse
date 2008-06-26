<?php
// $Id$

/**
 * @file
 * Themeable functions for Google Custom Search Engine.
 */

/**
 * The search results page can be themed/customized.
 */
function theme_google_cse_results($form = TRUE, $self = FALSE) {
  $query = array(
    'q' => isset($_GET['query']) ? $_GET['query'] : '',
    'cx' => variable_get('google_cse_cx', ''),
    'cof' => variable_get('google_cse_cof_google', 'FORID:0'),
    'sitesearch' => isset($_GET['sitesearch']) ? $_GET['sitesearch'] : google_cse_sitesearch(),
  ) + google_cse_advanced_settings();
  $output = $form ? drupal_get_form('google_cse_results_searchbox_form', $self) : '';
  $output .= '<div id="google-cse-results"><noscript>';
  $output .= t('!google, or enable JavaScript to view them here.', array('!google' => l(t('View the results at Google'), 'http://'. variable_get('google_cse_domain', 'www.google.com') .'/cse', array('query' => $query))));
  $output .= '</noscript></div>
    <script type="text/javascript">
    //<![CDATA[
      var googleSearchIframeName = "google-cse-results";
      var googleSearchFormName = "google-cse-results-searchbox-form";
      var googleSearchFrameWidth = '. intval(variable_get('google_cse_results_width', 600)) .';
      var googleSearchFrameborder = 0;
      var googleSearchDomain = "'. check_plain(variable_get('google_cse_domain', 'www.google.com')) .'";
      var googleSearchPath = "/cse";
    //]]>
    </script>
    <script type="text/javascript" src="http://www.google.com/afsonline/show_afs_search.js"></script>';
  return $output;
}
