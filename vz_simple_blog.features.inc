<?php
/**
 * @file
 * vz_simple_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vz_simple_blog_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function vz_simple_blog_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function vz_simple_blog_image_default_styles() {
  $styles = array();

  // Exported image style: scale_640.
  $styles['scale_640'] = array(
    'name' => 'scale_640',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '640',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function vz_simple_blog_node_info() {
  $items = array(
    'openpublish_blog_post' => array(
      'name' => t('Blog Post'),
      'base' => 'node_content',
      'description' => t('Used to create a single post to a column or blog.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
