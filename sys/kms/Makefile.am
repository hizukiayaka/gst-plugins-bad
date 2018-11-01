plugin_LTLIBRARIES = libgstkms.la libgstrga.la

libgstkms_la_SOURCES = 			\
	gstkmssink.c				\
	gstkmsutils.c				\
	gstkmsallocator.c			\
	gstkmsbufferpool.c			\
	$(NUL)

libgstkms_la_CFLAGS = 			\
	$(GST_PLUGINS_BASE_CFLAGS) 		\
	$(GST_BASE_CFLAGS) 			\
	$(GST_VIDEO_CFLAGS)			\
	$(GST_ALLOCATORS_CFLAGS)		\
	$(GST_CFLAGS) 				\
	$(KMS_DRM_CFLAGS) 			\
	$(NULL)

libgstkms_la_LIBADD = 			\
	$(GST_PLUGINS_BASE_LIBS) 		\
	$(GST_BASE_LIBS) 			\
	$(GST_VIDEO_LIBS)			\
	$(GST_ALLOCATORS_LIBS)			\
	$(GST_LIBS) 				\
	$(KMS_DRM_LIBS) 			\
	$(NULL)

libgstkms_la_LDFLAGS = 			\
	$(GST_PLUGIN_LDFLAGS)			\
	$(NULL)

libgstrga_la_SOURCES = 			\
	gstrgasink.c				\
	gstkmsutils.c				\
	gstkmsallocator.c			\
	gstkmsbufferpool.c			\
	$(NUL)

libgstrga_la_CFLAGS = 			\
	$(GST_PLUGINS_BASE_CFLAGS) 		\
	$(GST_BASE_CFLAGS) 			\
	$(GST_VIDEO_CFLAGS)			\
	$(GST_ALLOCATORS_CFLAGS)		\
	$(GST_CFLAGS) 				\
	$(KMS_DRM_CFLAGS) 			\
	$(RK_RGA_CFLAGS)			\
	$(NULL)

libgstrga_la_LIBADD = 			\
	$(GST_PLUGINS_BASE_LIBS) 		\
	$(GST_BASE_LIBS) 			\
	$(GST_VIDEO_LIBS)			\
	$(GST_ALLOCATORS_LIBS)			\
	$(GST_LIBS) 				\
	$(KMS_DRM_LIBS) 			\
	$(RK_RGA_LIBS)				\
	$(NULL)

libgstrga_la_LDFLAGS = 			\
	$(GST_PLUGIN_LDFLAGS)			\
	$(NULL)

noinst_HEADERS = 				\
	gstkmssink.h 				\
	gstkmsutils.h				\
	gstkmsallocator.h			\
	gstkmsbufferpool.h			\
	gstrgasink.h 				\
	$(NULL)
