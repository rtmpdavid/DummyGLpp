
DGL_CORE_DIR := core
DGL_BACKENDS_DIR := backends

DGL_BACKENDS_TO_BUILD := sdl2

DGL_LIBS_DIR := lib
DGL_STATIC_DIR := static
DGL_BUILD_DIR := build

##build settings
CXX ?= g++
CXXFLAGS := -Og -g
INCLUDES := 
LIBS := -lfmt
LINK_FLAGS ?= 
SO_LINK_FLAGS ?= -shared -fPIC
# A_LINK_FLAGS ?= -fPIC
##

DGL_BACKEND_DIRS := $(DGL_BACKENDS_TO_BUILD:%=$(DGL_BACKENDS_DIR)/%)
DGL_BACKEND_MKS := $(DGL_BACKEND_DIRS:%=%/backend.mk)
DGL_BACKEND_LIBS := $(DGL_BACKEND_DIRS:%=$(DGL_BUILD_DIR)/%.a)

include $(DGL_CORE_DIR)/core.mk
include $(DGL_BACKEND_MKS)

backends: $(DGL_BACKEND_LIBS)

all: dgl.a $(BACKEND_LIBS)
all: dirs

dgl.a: $(OBJECTS)
	@echo "Making $@"
	@ar rcs $(DGL_STATIC_DIR)/$@ $(OBJECTS)

dgl.so: dgl_core.a $(DGL_BACKEND_LIBS)
	@$(CXX) $(CXXFLAGS) $(LINK_FLAGS) $(SO_LINK_FLAGS) $(DGL_BUILD_DIR)/dgl_core.a $(DGL_BACKEND_LIBS) -o $(DGL_LIBS_DIR)/$@

.PHONY: dirs
dirs:
	@mkdir -p $(DGL_BUILD_DIR)
	@mkdir -p $(DGL_BUILD_DIR)/$(DGL_CORE_DIR)
	@mkdir -p $(DGL_BUILD_DIR)/$(DGL_BACKENDS_DIR)
	@mkdir -p $(DGL_LIBS_DIR)
	@mkdir -p $(DGL_STATIC_DIR)
	@mkdir -p $(dir $(OBJECTS))
	@mkdir -p $(dir $(DGL_BACKEND_LIBS))

.PHONY: clean
clean:
	rm -r $(DGL_BUILD_DIR) $(DGL_STATIC_DIR) $(DGL_LIBS_DIR)

include test/test.mk

-include $(OBJECTS:.o=.d)
