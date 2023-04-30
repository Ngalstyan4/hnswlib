narek@c10:~/vectorsearch/hnswlib/build$ldd example_mt_je_search
        linux-vdso.so.1 (0x00007ffe1a3cd000)
        libjemalloc.so.2 => /usr/local/lib/libjemalloc.so.2 (0x00007fdbf0cbc000)
        libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007fdbf0933000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007fdbf0595000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007fdbf037d000)
        libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007fdbf015e000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fdbefd6d000)
        libdl.so.2 => /lib/x86_64-linux-gnu/libdl.so.2 (0x00007fdbefb69000)
        /lib64/ld-linux-x86-64.so.2 (0x00007fdbf1393000)
narek@c10:~/vectorsearch/hnswlib/build$ldd example_mt_search
        linux-vdso.so.1 (0x00007ffc18de1000)
        libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f4762fa5000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f4762c07000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f47629ef000)
        libpthread.so.0 => /lib/x86_64-linux-gnu/libpthread.so.0 (0x00007f47627d0000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f47623df000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f4763546000)

narek@c10:~/vectorsearch/hnswlib/build$./example_mt_search 
Indexing time: 12660ms
Query time: 1323ms
Recall: 0.35836
narek@c10:~/vectorsearch/hnswlib/build$./example_mt_je_search 
Indexing time: 12365ms
Query time: 1284ms
Recall: 0.35546
narek@c10:~/vectorsearch/hnswlib/build$
