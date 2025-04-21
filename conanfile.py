from conan import ConanFile


class MostiConan(ConanFile):
    name = "my_project"
    version = "0.1"
    settings = "os", "compiler", "build_type", "arch"
    requires = [
        "gtest/1.13.0",
    ]
    generators = "CMakeDeps", "CMakeToolchain"

    def configure(self):
        # Static link gtest
        self.options["gtest"].shared = False
