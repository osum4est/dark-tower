#include <iostream>
#include <cxxopts.hpp>

void start_emulator() {
    std::cout << "Starting emulator..." << std::endl;

}

void disassemble() {
    std::cout << "Disassembling..." << std::endl;
}

int main(int argc, char *argv[]) {
    cxxopts::Options options("Dark Tower", "Command line interface for Dark Tower utilities.");
    options.positional_help("<binary>").show_positional_help();
    options.parse_positional({"binary"});
    options.add_options()
            ("e,emulator", "Emulate Dark Tower in the terminal.")
            ("d,disassemble", "Disassemble the Dark Tower binary to readable TM1400 assembly.")
            ("b,binary", "The Dark Tower binary to use.", cxxopts::value<std::vector<std::string>>())
            ("h,help", "Show this help text.");

    try {
        auto result = options.parse(argc, argv);

        if (result.count("help")) {
            std::cout << options.help() << std::endl;
            exit(0);
        }

        if (!result.count("binary")) {
            std::cerr << "Binary file not specified!" << std::endl;
            exit(1);
        }

        if (result.count("emulator"))
            start_emulator();
        else if (result.count("disassemble"))
            disassemble();
        else
            std::cout << "Nothing to do..." << std::endl;
    } catch (const cxxopts::OptionException &e) {
        std::cout << options.help() << std::endl;
        exit(1);
    }

    return 0;
}
