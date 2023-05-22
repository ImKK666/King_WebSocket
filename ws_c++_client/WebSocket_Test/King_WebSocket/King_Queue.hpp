#pragma once
#include <mutex>
#include <deque>

template< class T >
class King_Queue {
    mutable std::mutex m;
    std::deque< T >    data;

public:
    void push( const T &input ) {
        std::lock_guard< std::mutex > L( m );
        data.push_back( input );
    }

    bool pop( T &output ) {
        std::lock_guard< std::mutex > L( m );
        if( data.empty( ) ) {
            return false;
        }
        output = data.front( );
        data.pop_front( );
        return true;
    }
};