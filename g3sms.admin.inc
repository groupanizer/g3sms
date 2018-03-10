<?php

/**
 * Settings form
 */
function g3sms_settings_form($form, $form_state) {

  $form = array();
  $form['message'] = array(
    '#markup' => t("Enter your EZ Texting username and password here. If you don't have one, sign up for an account at !link.",
      array('!link' => l('EZ Texting', 'https://go.eztexting.com', array('attributes'=>array('target'=>'_blank'))))),
  );

  $form['note'] = array(
    '#markup' => "<br>" . t("(Please note that EZ Texting only works in North America at this time!)"),
  );

  $form['g3sms_eztexting_username'] = array(
    '#type' => 'textfield',
    '#title' => 'EZTexting username',
    '#default_value' => variable_get('g3sms_eztexting_username'),
  );

  $form['g3sms_eztexting_password'] = array(
    '#type' => 'textfield',
    '#title' => 'EZTexting password',
    '#default_value' => variable_get('g3sms_eztexting_password'),
  );

  return system_settings_form($form);
}
