DGL_CORE_SOURCES = $(shell find $(DGL_CORE_DIR) -name '*.cpp' -printf '%T@\t%p\n' | sort -k 1nr | cut -f2-)
DGL_CORE_OBJECTS = $(DGL_CORE_SOURCES:%.cpp=$(DGL_BUILD_DIR)/%.o)

OBJECTS += $(DGL_CORE_OBJECTS)
INCLUDES += -I$(DGL_CORE_DIR) 

CORE_INCLUDES := 
DGL_CORE_LDFLAGS :=
CORE_CXXFLAGS := -fPIC

dgl_core.a: $(DGL_CORE_OBJECTS)
	@echo "Compiling $(DGL_CORE_OBJECTS) -> $@"
	@ar rcs $(DGL_BUILD_DIR)/$@ $^

$(DGL_BUILD_DIR)/$(DGL_CORE_DIR)/%.o: $(DGL_CORE_DIR)/%.cpp
	@echo "Compiling: $< -> $@"
	@$(CMD_PREFIX)$(CXX) $(CXXFLAGS) $(CORE_CXXFLAGS) -I$(DGL_CORE_DIR) $(CORE_INCLUDES) -MP -MMD -c $< -o $@

