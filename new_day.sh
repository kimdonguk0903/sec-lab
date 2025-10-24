#!/usr/bin/env bash
if [ -z "${1-}" ]; then
  echo "Usage: ./new_day.sh dayN-description"
  exit 1
fi
mkdir -p "$1"
cat > "$1/README.md" <<MD
# $1

## 목표

## 실습 파일

## 실행 방법

## 결과 요약

MD

echo "Created $1 with README.md"
