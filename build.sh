#!/bin/bash
echo "🔨 Compilando o projeto Portal Acadêmico..."

# Cria a pasta build se não existir
mkdir -p build

# Compila todos os fontes
g++ src/main.cpp src/core/*.cpp src/utils/*.cpp src/portals/*.cpp -lsodium -o build/portal-academico

# Verifica se deu certo
if [ $? -eq 0 ]; then
    echo "✅ Compilado com sucesso! Executável gerado em: build/portal-academico"
    # Exibe o tamanho do executável
    echo "📦 Tamanho do binário:"
    du -h build/portal-academico
else
    echo "❌ Falha na compilação."
fi