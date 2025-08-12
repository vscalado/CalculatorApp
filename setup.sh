#!/bin/bash

# Script: install_and_build.sh
# Description: Instala dependências e compila o projeto CalculatorApp no Ubuntu 22.04

echo "🔧 Atualizando pacotes..."
sudo apt update

echo "📦 Instalando dependências do Qt6..."
sudo apt install -y qt6-base-dev qt6-base-dev-tools qt6-tools-dev qt6-tools-dev-tools

echo "📦 Instalando dependências do OpenGL..."
sudo apt install -y libgl-dev libopengl-dev

echo "📦 Instalando yaml-cpp..."
sudo apt install -y libyaml-cpp-dev

echo "✅ Dependências instaladas com sucesso."

echo "📁 Verificando diretório do projeto..."
if [ ! -d "CalculatorApp" ]; then
    echo "❌ Diretório CalculatorApp não encontrado. Certifique-se de estar na pasta correta."
    exit 1
fi

echo "🔨 Configurando build com CMake..."
mkdir -p CalculatorApp/build
cd CalculatorApp/build
cmake ..
make

echo "🚀 Build concluído. Execute com ./CalculatorApp"