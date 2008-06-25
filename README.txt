// $Id$

Google Custom Search Engine (CSE) is an embedded search engine that can 
be used to search any set of one or more sites.  No Google API key is 
required.  More info at http://www.google.com/coop/cse/

After installing this module, configure it by entering Google's 
alphanumeric ID for your CSE.  Once you have granted permission for one 
or more roles to search the Google CSE, the search page can be found at 
search/google, and a search block can also be enabled.

Due to Google and Drupal both making use of "q", this module requires 
that clean URLs be enabled.

In addition to the CSE functionality, SiteSearch on one domain can 
optionally be configured.  Radio buttons allow users to search on either 
the SiteSearch or the CSE, and searches can default to either option.

The collapsed advanced settings on the settings page provide various 
customizations such as country and language preferences.  For example, 
with the Locale module enabled, the Google CSE user interface language 
can be selected dynamically based on the current user's language.

The "Google CSE search" module is an optional glue module that 
integrates Google CSE with Drupal's core Search API.  After enabling 
this module, search queries will be logged by the Search module and 
users can click between available search tabs such as search/node.

The current maintainer does not plan to add new features to this module, 
such as support for multiple CSEs; however, patches providing new 
features are welcome and will be reviewed.

To configure this module, you will need your CSE's alphanumeric ID 
("cx").  Go to your CSE manage page, click on control panel and then 
click on code.  The only part you need is the cx value; to isolate it 
you'll have to copy/paste the code into a text editor.

Authored and maintained by: http://drupal.org/user/12302

For bugs, feature requests and support requests, please use the issue 
queue at http://drupal.org/project/issues/google_cse
