// This will works perfectly fine as both threads will acquire locks in the same order (mtx1 followed by mtx2) preventing deadlock.
    std::thread t3(safeA);
    std::thread t4(safeB);
    
    t3.join();
    t4.join();