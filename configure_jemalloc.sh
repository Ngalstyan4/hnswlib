 wget https://github.com/jemalloc/jemalloc/releases/download/5.3.0/jemalloc-5.3.0.tar.bz2
 bzip2 -d jemalloc-5.3.0.tar.bz2
 tar -xvf ./jemalloc-5.3.0.tar jemalloc-5.3.0/
 cd jemalloc-5.3.0/
 ./configure
 make
 sudo make install
 jemalloc-config --libdir
 #LD_PRELOAD=`jemalloc-config --libdir`/libjemalloc.so.`jemalloc-config --revision` /usr/bin/time -v python3 example.py
 #MALLOC_CONF=stats_print:true LD_PRELOAD=`jemalloc-config --libdir`/libjemalloc.so.`jemalloc-config --revision` /usr/bin/time -v python3 example.py
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/loca/lib
