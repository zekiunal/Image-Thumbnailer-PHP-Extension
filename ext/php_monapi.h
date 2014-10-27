
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_MONAPI_H
#define PHP_MONAPI_H 1

#include "kernel/globals.h"

#define PHP_MONAPI_NAME        "monapi"
#define PHP_MONAPI_VERSION     "0.0.1"
#define PHP_MONAPI_EXTNAME     "monapi"
#define PHP_MONAPI_AUTHOR      ""
#define PHP_MONAPI_ZEPVERSION  "0.5.7a"
#define PHP_MONAPI_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(monapi)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(monapi)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(monapi)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(monapi_globals_id, zend_monapi_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (monapi_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_monapi_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(monapi_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(monapi_globals)
#endif

#define zephir_globals_def monapi_globals
#define zend_zephir_globals_def zend_monapi_globals

extern zend_module_entry monapi_module_entry;
#define phpext_monapi_ptr &monapi_module_entry

#endif
