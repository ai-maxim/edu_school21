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
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'mix' );

/** MySQL database password */
define( 'DB_PASSWORD', 'aq' );

/** MySQL hostname */
define( 'DB_HOST', 'mariadb' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

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
define( 'AUTH_KEY',         'MD=#(FT&1x_eWB!J4R5 T<ySRgl /vH)7oOYgN04^-b_bgMj?,@C7<K9Wa8v{W`U' );
define( 'SECURE_AUTH_KEY',  'ioJSh?O@[S%2efqh;i^)F*ZPO4Jq_;9<9dE6~E2r#;d5Da)it-5A6Hkz.L >VxR1' );
define( 'LOGGED_IN_KEY',    '|MeA$&&RU]fq?N-pQEocxC#a4F&@m%f.U>{A^Rpu+Mz Q+Zqr?^<<V(|]=mS-}d/' );
define( 'NONCE_KEY',        '/b$E3ib+Mm6WDyA[$.ub3b0CpHXb#h{7SHb+WAdE`3H-cZA8p9^FPg!VNZs>IZJx' );
define( 'AUTH_SALT',        'xP`-io/M Wsu1Elyz+(7]w^^+/7x#xs)gOhnrVJ1Z4d-peKie9j{*V7@U$Ri^Xmu' );
define( 'SECURE_AUTH_SALT', '-}-0hvzL&Zd-0ORi$NBHI0o:oLc9<9mHS5Tm(2`coIDrTgNEo@Mf~iwxi5|z4E*:' );
define( 'LOGGED_IN_SALT',   '&^mMBR$q*q>5T$faME]SU%aIsg|1eIZ+pyiCcOqJu}fS.va_:_/M:+N2$^J[0o9e' );
define( 'NONCE_SALT',       '*i)(K/Sj6S7=)dgX8ca%v&]|hb:EGW$q~iKU#:qWC%^[h]Ec.6pjnGUq{YVY{[]&' );

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

