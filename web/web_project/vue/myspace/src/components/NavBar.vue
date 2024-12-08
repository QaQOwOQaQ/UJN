<template>
  <nav class="navbar navbar-expand-lg bg-body-tertiary">
    <div class="container">
      <router-link class="navbar-brand" :to="{ name: 'home' }">BBspace</router-link>
      <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarText"
        aria-controls="navbarText" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="collapse navbar-collapse" id="navbarText">
        <ul class="navbar-nav me-auto mb-2 mb-lg-0">
          <li class="nav-item">
            <router-link class="nav-link" :to="{ name: 'home' }">Home</router-link>
          </li>
          <li class="nav-item">
            <router-link class="nav-link" :to="{ name: 'userlist' }">UserList</router-link>
          </li>
          <!-- <li class="nav-item">
            <router-link class="nav-link" :to="{ name: 'userprofile', params: { userID: 2 } }">UserProfile</router-link>
          </li> -->
        </ul>
        <span class="navbar-text">
          <!-- 未登录状态现实的内容 -->
          <ul class="navbar-nav me-auto mb-2 mb-lg-0" v-if="!$store.state.user.is_login">
            <li class="nav-item">
              <router-link class="nav-link" :to="{ name: 'login' }">Log in</router-link>
            </li>
            <li class="nav-item">
              <router-link class="nav-link" :to="{ name: 'register' }">Register</router-link>
            </li>
          </ul>
          <!-- 已经登陆后显示的内容 -->
          <ul class="navbar-nav me-auto mb-2 mb-lg-0" v-else>
            <li class="nav-item">
              <router-link class="nav-link" :to="{ name: 'userprofile', params: { userID: $store.state.user.id }}">
                {{ $store.state.user.username }}
              </router-link>
            </li>
            <li class="nav-item">
              <a class='nav-link' style="cursor: pointer" @click="logout">quit</a>
            </li>
          </ul>
        </span>
      </div>
    </div>
  </nav>
</template>



<script>
import { useStore } from 'vuex';
 
export default {
  name: 'NavBar',
  setup() {
    const store = useStore();
    const logout = () => {
      store.commit('logout');
    };
    return {
      logout,
    }
  }
}
</script>

<style scoped>
</style>