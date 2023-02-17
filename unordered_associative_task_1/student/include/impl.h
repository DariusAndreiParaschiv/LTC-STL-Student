#pragma once
#include <string>
#include <vector>

struct Song
{
public:
    Song(const std::string& name)
             : track_name {name}
    {
    }

    const std::string& name() const
    {
        return track_name;
    }

    bool operator<(const Song&) = delete;

private:
    std::string track_name;
};

using playlist = std::vector<Song>;

/**
 * @todo Implement function that will check if one playlist has the same songs
 * as the second one
 *
 * @example is_same_content({"a", "b", "c", "d"}, {"a", "c", "d", "b"}) -> true
 * @example is_same_content({"a", "b", "c", "d"}, {"a", "b", "e", "c"}) -> false
 *
 * @return true if first playlist is anagram of second
 */
bool is_same_content(const playlist& first_playlist, const playlist& second_playlist)
{
    if(first_playlist.size() != second_playlist.size())
        return false;

    playlist temp_playlist {first_playlist.begin(), first_playlist.end()};

    for(auto track : second_playlist)
    {
        for(auto it = temp_playlist.begin(); it != temp_playlist.end(); ++it)
        {
            if(it->name() == track.name())
            {
                temp_playlist.erase(it);
                break;
            }
        }
    }

    if(temp_playlist.empty())
        return true;
    else
        return false;
};
