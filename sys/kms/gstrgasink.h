/* GStreamer
 *
 * Copyright (C) 2016 Igalia
 *
 * Authors:
 *  Víctor Manuel Jáquez Leal <vjaquez@igalia.com>
 *  Javier Martin <javiermartin@by.com.es>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef __GST_RGA_SINK_H__
#define __GST_RGA_SINK_H__

#include <gst/video/gstvideosink.h>

G_BEGIN_DECLS

#define GST_TYPE_RGA_SINK \
  (gst_rga_sink_get_type())
#define GST_RGA_SINK(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), GST_TYPE_RGA_SINK, GstRGASink))
#define GST_RGA_SINK_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass), GST_TYPE_RGA_SINK, GstRGASinkClass))
#define GST_IS_RGA_SINK(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_TYPE_RGA_SINK))
#define GST_IS_RGA_SINK_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass), GST_TYPE_RGA_SINK))

typedef struct _GstRGASink GstRGASink;
typedef struct _GstRGASinkClass GstRGASinkClass;

struct _GstRGASink {
  GstVideoSink videosink;

  /*< private >*/
  gint fd;
  gint conn_id;
  gint crtc_id;
  gint plane_id;
  guint pipe;
  GData *conn_props;
  GData *crtc_props;
  GHashTable *plane_res;

  /* crtc data */
  guint16 hdisplay, vdisplay;
  guint32 buffer_id;

  /* capabilities */
  gboolean has_prime_import;
  gboolean has_prime_export;
  gboolean has_async_page_flip;
  gboolean can_scale;

  gboolean modesetting_enabled;
  gboolean restore_crtc;
  GstStructure *connector_props;
  GstStructure *plane_props;

  GstVideoInfo vinfo;
  GstVideoInfo conv_vinfo;
  GstCaps *allowed_caps;
  GstBufferPool *pool;
  GstAllocator *allocator;
  GstBuffer *last_buffer;

  gchar *devname;
  gchar *bus_id;

  guint32 mm_width, mm_height;
  gpointer saved_crtc;
  GstPoll *poll;
  GstPollFD pollfd;

  /* render video rectangle */
  GstVideoRectangle render_rect;

  /* reconfigure info if driver doesn't scale */
  GstVideoRectangle pending_rect;
  gboolean reconfigure;
};

struct _GstRGASinkClass {
  GstVideoSinkClass parent_class;
};

GType gst_rga_sink_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif /* __GST_RGA_SINK_H__ */
