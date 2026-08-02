.PHONY: run clean setup

ifeq ($(OS),Windows_NT)
    CORES := 4
else
    CORES := $(shell nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)
endif

run:
	@echo "Configurando e compilando o projeto..."
	@mkdir -p build
	@cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug
	@cd build && cmake --build . -j$(CORES)
	@echo "Build concluído. Executando..."
	@./build/engineV4

setup:
	@echo "Baixando dependências..."
	@mkdir -p build
	@cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug
	@echo "Dependências configuradas."

clean:
	@echo "Limpando build..."
	@rm -rf build
	@echo "Build limpo."

ci:
	@mkdir -p build
	@cd build && cmake .. -DCMAKE_BUILD_TYPE=Release
	@cd build && cmake --build . --config Release -j$(CORES)