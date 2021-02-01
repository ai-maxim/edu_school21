<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'database_name_here' );

/** MySQL database username */
define( 'DB_USER', 'username_here' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password_here' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '0uhKdm3hZ$Bs~5B``M+E<& W^-e}a?[_;D:#i9W.xiNQT#HN4p]29mO=%D%p;M7+');
define('SECURE_AUTH_KEY',  '#Q-sXr-Xw|] +fsoY Hp82S_E*_sv+g&K-wx?3vh1!DhicVav9-{fPb(pze/37RM');
define('LOGGED_IN_KEY',    't>UA[wYrt#f-$$g}kzYGn.`6T~%WG }WXEMMjsFTJ6haLl{z0C1tr#EU6m&L1c}v');
define('NONCE_KEY',        '2s:QfG|FKS*yR.q>)EP>E?r_Eyb;d-W?RjAM]#v*>UxWo<s~w(`/99]gDd]64VCx');
define('AUTH_SALT',        '4m+7c^+ly0/>%?0[~9^_|D^zD/}Y+>RTm4YKXhDvz-I|F<R={i>W-WgBkFdOyY@o');
define('SECURE_AUTH_SALT', 'E:tq`{lRD<U)/1y{fiH{k6{}RcXYTt{b1$:-kd$ZwH;?JVs@kPRkqoFn92ufr2&V');
define('LOGGED_IN_SALT',   'A*C[lOep9+Z %T~u+>%}l+YE)&j?aW`-h%IJ-ZMzk&cM.46d[wwyMVJ#i<5yNOk)');
define('NONCE_SALT',       'f mcUaGPgk[h47[g(Y]yBaHs%KCA1{z}|)0$=UY~9|F=T(n=^.}|{B`X!f_$}<Le');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
