<?php


/**
 * test page
 */
function g3sms_test() {
  $test_button = drupal_get_form('g3sms_test_button');
  $ra['test'] = array(
    '#markup' => drupal_render($test_button),
  );
  return $ra;
}

function g3sms_test_button($form, $form_state) {
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Test',
  );
  return $form;
}

function g3sms_test_button_submit($form, $form_state) {

  $query = array(
    'User'          => 'groupanizer',
    'Password'      => 'acoustix',
    'PhoneNumbers'  => array('7788681853'),
    'Subject'       => 'From Tom',
    'Message'       => 'Sending from CG on my laptop',
    //'Groups'        => array('honey lovers'),
    //'StampToSend'   => '1305582245',
    //'MessageTypeID' => 1
  );

  $url_encoded_query = drupal_http_build_query($query);

  $options = array(
    'method' => 'POST',
    'data' => $url_encoded_query,
    'timeout' => 15,
    'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
  );

  $result = drupal_http_request(
    'https://app.eztexting.com/sending/messages?format=json',
    $options
  );

  dpm($result);
  return 'ok';

 
/*
  echo 'Status: ' . $json->Status . "\n" .
  'Message ID : ' . $json->Entry->ID . "\n" .
  'Subject: ' . $json->Entry->Subject . "\n" .
  'Message: ' . $json->Entry->Message . "\n" .
  'Message Type ID: ' . $json->Entry->MessageTypeID . "\n" .
  'Total Recipients: ' . $json->Entry->RecipientsCount . "\n" .
  'Credits Charged: ' . $json->Entry->Credits . "\n" .
  'Time To Send: ' . $json->Entry->StampToSend . "\n" .
  'Phone Numbers: ' . implode(', ' , $phoneNumbers) . "\n" .
  'Groups: ' . implode(', ' , $groups) . "\n" .
  'Locally Opted Out Numbers: ' . implode(', ' , $localOptOuts) . "\n" .
  'Globally Opted Out Numbers: ' . implode(', ' , $globalOptOuts) . "\n";
*/

}

