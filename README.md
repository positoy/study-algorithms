#완전탐색

    recursive(situation) {
        int count = 0;
        for (all possible cases in given situation)
        {
            apply new situation
            count += recursive(new situation)
            cancel new situation
        }
        return count;
    }
    std::cout << recursive(all cases) << std::endl;
    
