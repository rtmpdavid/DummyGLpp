OBJECTS += $(DGL_BUILD_DIR)/test/test.o

$(DGL_BUILD_DIR)/test/test.o: test/main.cpp
	@echo "Compiling: $< -> $@"
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c test/main.cpp -o $(DGL_BUILD_DIR)/test/test.o

test: all
test: $(DGL_BUILD_DIR)/test/test.o dgl.a
	@echo "Making test"
	@$(CXX) $(CXXFLAGS) $(LINK_FLAGS) $(LIBS) $(DGL_BUILD_DIR)/test/test.o $(DGL_STATIC_DIR)/dgl.a -o testb
