<template>
  <NavBar />
  <!-- 如果不加:key="$route.fullPath" ，会有一个bug：当我们点开某个人的profile时，
  再点击自己的profile不会跳转，这是因为浏览器把 http://localhost:8080/userprofile/* 都当作一个网址了
  因此我们要显示区分开他们 -->
  <router-view :key="$route.fullPath" />
</template>

<script>
// 注意加上分号;
import 'bootstrap/dist/css/bootstrap.css';
import 'bootstrap/dist/js/bootstrap';
import NavBar from './components/NavBar'; // default import 不需要加{}

export default {
  name: "App",
  components: {
    NavBar, // <==> navbar_alias: NavBar
  }
}
</script>

<style>
</style>
