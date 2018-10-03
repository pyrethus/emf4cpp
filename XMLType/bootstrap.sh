#!/bin/sh

../org.csu.emf4cpp.generator/emf4cpp.generator.sh \
    --internal \
    XMLType.ecore

# When the created code is compiled, the emf4cpp source directory has to be
# used, because it is not yet installed.
patch -N -p0 -r- <<EOF
--- CMakeLists.txt      2018-10-03 11:04:12.950764558 +0200
+++ CMakeLists.txt.mod  2018-10-03 10:35:49.933080453 +0200
@@ -28,4 +28,4 @@
   include(${cmake})
 endforeach(cmake)
 
-
+include_directories( ../emf4cpp )
EOF
