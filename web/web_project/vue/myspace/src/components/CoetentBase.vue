<template>
    <div class="home">
        <div class="container">
            <div class="card">
                <div class="card-body">
                    <slot></slot>   
                    <!-- 所有<Content>标签中的元素（子元素）都会放在slot里面
                        由此获得content里面的内容 -->
                </div>
            </div>
        </div>
    </div>
</template>

<script>
export default {
    name: 'ContentBase',
}
</script>

<style scoped>
.container {
    margin-top: 20px;
}
</style>