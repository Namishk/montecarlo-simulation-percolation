#include <cmath>
#include <iomanip>
#include <ostream>
#include <string>
#include <chrono>
#include <iostream>
#include <thread>

class ProgressBar
{
    static const auto overhead = sizeof " [100%]";

    std::ostream& os;
    const std::size_t bar_width;
    std::string message;
    const std::string full_bar;

 public:
    ProgressBar(std::ostream& os, std::size_t line_width,
                 std::string message_, const char symbol = '|')
        : os{os},
          bar_width{line_width - overhead},
          message{std::move(message_)},
          full_bar{std::string(bar_width, symbol) + std::string(bar_width, ' ')}
    {
        if (message.size()+1 >= bar_width || message.find('\n') != message.npos) {
            os << message << '\n';
            message.clear();
        } else {
            message += ' ';
        }
        write(0.0);
    }

    // not copyable
    ProgressBar(const ProgressBar&) = delete;
    ProgressBar& operator=(const ProgressBar&) = delete;

    ~ProgressBar()
    {
        write(1.0);
        os << '\n';
    }

    void write(double fraction);
};

void ProgressBar::write(double fraction)
{
    // clamp fraction to valid range [0,1]
    if (fraction < 0)
        fraction = 0;
    else if (fraction > 1)
        fraction = 1;

    auto width = bar_width - message.size();
    auto offset = bar_width - static_cast<unsigned>(width * fraction);

    os << '\r' << message;
    os.write(full_bar.data() + offset, width);
    os << " [" << std::setw(3) << static_cast<int>(100*fraction) << "%] " << std::flush;
}

// int main()
// {
//     ProgressBar progress{std::clog, 100u, "Working"};

//     for (auto i = 0.0;  i <= 100;  i++) {
//         progress.write(i/100.0);
//         // simulate some work
//         std::this_thread::sleep_for(std::chrono::milliseconds(100));
//     }
// }