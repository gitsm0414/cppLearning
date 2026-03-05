<로컬 폴더에서 vscode로 편집하고 깃헙과 연동하기>
1. vscode 에서 해당 폴더위치로 가고 터미널에, git clone <link_to_repository>
2. 그 폴더 안에 기존에 만들어 두었던 파일들 혹은 폴더를 옮겨놓기
3. git status -> 빨간색으로 새로 추가된 파일들 보일거임
4. git add .
5. git commit -m "....."
6. git push
7. 이러면 변경사항 적용 완료. 혹은 아예 새로 시작할때 즉 깃헙에서 레포지토리 새로 만들때도 이 방식대로.
    >> git cd 레포이름 / git clone <링크> / 그 다음 그냥 파일 만들고 add, commit, push 하면 됨.

<이미 로컬 프로젝트 있을 때>
git init ~으로 하면 된다는데
