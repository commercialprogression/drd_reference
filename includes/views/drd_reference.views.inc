<?php

/**
 * Implements hook_field_views_data().
 */
function drd_reference_field_views_data($field) {
  // Check to see that drd_views module exists.
  if (module_exists('drd_views')) {
    $data = field_views_field_default_views_data($field);

    foreach ($data as $table_name => $table_data) {
      $field_name = $field['field_name'] . '_did';

      $data[$table_name][$field_name]['relationship'] = array(
        'handler' => 'views_handler_relationship',
        'base' => 'drd_domain',
        'base field' => 'did',
        'label' => t('DRD Reference'),
        'group' => t('DRD'),
        'title' => t('Referenced DRD'),
        'help' => t('A bridge to the referenced DRD domain'),
      );
    }

    return $data;
  }
}